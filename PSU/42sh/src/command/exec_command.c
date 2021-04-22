/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** exec_command
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "mlib.h"
#include "minishell.h"

static const my_func_t builtin_table[SIZE_FUNC] = {
    {&my_cd, "cd"},
    {&my_setenv, "setenv"},
    {&my_unsetenv, "unsetenv"},
    {&my_exit, "exit"},
    {&my_history, "history"},
    {&my_excla, "!*"},
    {&alias, "alias"},
    {&unalias, "unalias"},
    {&my_unset, "unset"},
    {&my_set, "set"}
};

static const my_func_t exec_table[SIZE_EXEC] = {
    {&my_echo, "echo"},
    {&my_exec, "./*"},
    {&my_exec, ""}
};

int is_empty(char *str)
{
    for (int i = 0 ; str[i] != '\0' ; i += 1) {
        if (str[i] != ' ')
            return (-1);
    }
    return (0);
}

int handle_builtin(data_t *data, char **arg)
{
    int i = 0;
    int result = 0;
    int exec = 0;

    if (arg == NULL || arg[0] == NULL)
        return (ERROR);
    if (is_empty(arg[0]) == 0)
        return (SUCCESS);
    for ( ; i < SIZE_FUNC ; i += 1) {
        if (str_compare(arg[0], builtin_table[i].name) == 0) {
            result = (builtin_table[i].func_ptr)(data, arg);
            exec = 1;
            break;
        }
    }
    if (exec == 0)
        return (-1);
    return (result);
}

int handle_other(data_t *data, char **arg)
{
    int i = 0;
    int result = 0;

    if (arg == NULL || arg[0] == NULL)
        return (ERROR);
    if (is_empty(arg[0]) == 0)
        return (SUCCESS);
    for ( ; i < SIZE_EXEC ; i += 1) {
        if (str_compare(arg[0], exec_table[i].name) == 0 ||
        SIZE_EXEC - 1 == i) {
            result = (exec_table[i].func_ptr)(data, arg);
            break;
        }
    }
    if (i == SIZE_EXEC && arg[0][0] != '\0') {
        mputerror(arg[0]);
        mputerror(": Command not found.\n");
    }
    return (result);
}

void prepare_child(node_t *tree, data_t *data, int input[2], int ouput[2])
{
    if (ouput[1] > -1) {
        dup2(ouput[1], 1);
        close(ouput[1]);
    }
    if (ouput[0] > -1)
        close(ouput[0]);
    if (input[0] > -1) {
        dup2(input[0], 0);
        close(input[0]);
    }
    if (input[1] > -1)
        close(input[1]);
    if (handle_other(data, tree->command) == ERROR)
        exit (ERROR);
    exit (0);
}

int create_link(node_t *tree, data_t *data, int input[2], int ouput[2])
{
    pid_t cpid = -1;

    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        return (ERROR);
    } else if (cpid == 0) {
        prepare_child(tree, data, input, ouput);
    }
    if (input[0] != -1)
        close(input[0]);
    if (input[1] != -1)
        close(input[1]);
    data->child_nb++;
    return (SUCCESS);
}