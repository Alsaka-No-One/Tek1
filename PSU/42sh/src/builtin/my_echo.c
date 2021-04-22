/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Echo builtin
*/

#include "minishell.h"
#include "mlib.h"

int my_echo(data_t *data, char **input)
{
    mbool enter = true;
    int ptr = 1;

    (void)data;
    if (input[ptr] && mstrsame(input[ptr], "-n") == true) {
        enter = false;
        ptr++;
    }
    for ( ; input[ptr] ; ptr++) {
        mputstr(input[ptr]);
        mputchar(' ');
    }
    if (enter == true)
        mputchar('\n');
    return (SUCCESS);
}
