/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Handle "!"
*/

#include <string.h>
#include <stdlib.h>
#include "minishell.h"
#include "mlib.h"

#include <stdio.h>

static char *found_command_char(char **arg, data_t *data)
{
    char *command = NULL;
    char **temp = NULL;

    for (int i = data->history_index ; i >= 0 ; i--) {
        if (data->history[i])
            temp = marg2(data->history[i]);
        if (data->history[i] && temp && temp[0] && temp[1] &&
            temp[2] && mstrcmpltn(temp[2], arg[0]) == true) {
            marg_free(temp);
            command = mstr_cln(data->history[i]);
            data->history[i] = NULL;
            return (command);
        }
        if (data->history[i] && temp)
            marg_free(temp);
    }
    return (NULL);
}

static char *found_command(char **arg, data_t *data)
{
    char *command = NULL;

    if (mis_num(arg[0]) == true) {
        if (mgetnbr(arg[0]) > 0 && mgetnbr(arg[0]) < MAX_HISTORY
            && data->history[mgetnbr(arg[0])]) {
            command = mstr_cln(data->history[mgetnbr(arg[0])]);
            data->history[mgetnbr(arg[0])] = NULL;
            return (command);
        }
    } else
        command = found_command_char(arg, data);
    return (command);
}

static mbool command_not_found(data_t *data, char *command, char **arg)
{
    if (!command) {
        data->history[--data->history_index] = NULL;
        mputstr(arg[0]);
        marg_free(arg);
        mputstr(": Event not found.\n");
        return (true);
    }
    return (false);
}

static char *create_command(char *command, char **input)
{
    char **arg = marg2(command);
    char *new = malloc(sizeof(char *) * 256);

    if (!arg || !new)
        return (NULL);
    new[0] = '\0';
    for (int i = 2 ; arg[i] ; i++) {
        strcat(new, arg[i]);
        strcat(new, " ");
    }
    for (int i = 1 ; input[i] ; i++) {
        strcat(new, input[i]);
        strcat(new, " ");
    }
    marg_free(arg);
    free(command);
    return (new);
}

int my_excla(data_t *data, char **input)
{
    char **arg = NULL;
    char *command = NULL;

    if (!input[0][1])
        return (mputstr("!: Command not found.\n"));
    arg = marg(input[0], '!');
    if (!arg)
        return (ERROR);
    command = found_command(arg, data);
    if (command_not_found(data, command, arg) == true)
        return (SUCCESS);
    command = create_command(command, input);
    if (!command)
        return (ERROR);
    mputstr(command);
    mputchar('\n');
    data->history_index--;
    fill_history(command , data);
    marg_free(arg);
    return (split_parser(command, data));
}
