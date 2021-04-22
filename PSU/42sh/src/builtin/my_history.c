/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** History
*/

#include <stdlib.h>
#include <string.h>
#include "mlib.h"
#include "minishell.h"

int initialize_history(data_t *data)
{
    data->history_index = 0;
    data->history = malloc(sizeof(char *) * (MAX_HISTORY + 1));
    if (!(data->history))
        return (ERROR);
    for (int i = 0 ; i <= MAX_HISTORY ; i++)
        data->history[i] = NULL;
    return (SUCCESS);
}

int count_start_read(data_t *data, int nb_read)
{
    int i = data->history_index;

    if (nb_read == 0)
        nb_read = 1;
    for (int count = 0 ; i >= 0 ; i--) {
        if (data->history[i])
            count++;
        if (count >= nb_read)
            break;
    }
    return (i);
}

int my_history(data_t *data, char **input)
{
    int nb_read = 0;
    int i = 0;

    if (input[1]) {
        if (mis_num(input[1])) {
            nb_read = mgetnbr(input[1]);
        } else
            return (mputstr("history: Badly formed number.\n"));
    }
    if (input[1] && data->history_index - nb_read >= 0)
        i = count_start_read(data, nb_read);
    for ( ; i < data->history_index ; i++) {
        if (data->history[i]) {
            mputstr(data->history[i]);
            mputchar('\n');
        }
    }
    return (SUCCESS);
}
