/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** command_handler
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

static int norme(node_t *tree, int fd, int ouput[2])
{
    if (tree->symbol == SIMPLE_RIGHT)
        fd = open(tree->right->command[0], O_WRONLY | O_CREAT, 0644);
    else
        fd = open(tree->right->command[0], O_WRONLY | O_APPEND |
        O_CREAT, 0644);
    ouput[1] = fd;
    return (fd);
}

static int norme2(int fd, node_t *tree, int input[2], node_t **next)
{
    fd = input_pipe(tree);
    if (fd == -2)
        return (ERROR);
    else if (fd > 0)
        input[0] = fd;
    *next = (*next)->right;
    return (SUCCESS);
}

int handle_pipe(node_t *tree, data_t *data, int input[2])
{
    int fd = 0;
    node_t *next = tree->right;
    int ouput[2] = {-1, -1};

    if (handle_builtin(data, tree->left->command) != -1)
        return (SUCCESS);
    if (tree->symbol == PIPE) {
        if (pipe(ouput) == -1) {
            perror("pipe");
            return (ERROR);
        }
    } else if (tree->symbol == SIMPLE_RIGHT || tree->symbol == DOUBLE_RIGHT) {
        norme(tree, fd, ouput);
        next = next->right;
    } else if (tree->symbol == SIMPLE_LEFT || tree->symbol == DOUBLE_LEFT) {
        if (norme2(fd, tree, input, &next) == ERROR)
            return (ERROR);
    }
    if (create_link(tree->left, data, input, ouput) == ERROR)
        return (ERROR);
    return (command_handler(next, data, ouput));
}

int wait_child(data_t *data)
{
    int status = 0;

    while (data->child_nb > 0) {
        if (waitpid(-1, &status, 0) == -1) {
            perror("waitpid");
            return (ERROR);
        }
        display_status(status);
        data->child_nb--;
    }
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    return (0);
}

int command_handler(node_t *tree, data_t *data, int prev_pipe[2])
{
    int exit_value = 0;

    if (tree == NULL)
        return (SUCCESS);
    if (tree->symbol == 0) {
        if (handle_builtin(data, tree->command) == -1)
            create_link(tree, data, prev_pipe, (int[2]){-1, -1});
    } else {
        if (tree->symbol == PIPE || tree->symbol == SIMPLE_RIGHT ||
        tree->symbol == DOUBLE_RIGHT || tree->symbol == DOUBLE_LEFT ||
        tree->symbol == SIMPLE_LEFT)
            handle_pipe(tree, data, prev_pipe);
        else if (tree->symbol == COMA || tree->symbol == DOUBLE_PIPE ||
        tree->symbol == ESPER)
            cmd_seperator(tree, data, prev_pipe);
    }
    if (data->child_nb != 0)
        wait_child(data);
    return (exit_value);
}
