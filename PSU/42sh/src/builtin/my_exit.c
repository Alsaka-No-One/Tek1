/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** my_exit function
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "mlib.h"

int my_exit(data_t *data, char **input)
{
    int ac = mrow(input);

    (void)data;
    if (ac == 1) {
        mputstr("exit\n");
        exit(SUCCESS);
    }
    if (ac > 2) {
        mputstr("exit: Expression Syntax.\n");
        return (SUCCESS);
    }
    for (int i = 0 ; input[1][i] ; i++)
        if (input[1][i] < '0' || input[1][i] > '9') {
            mputstr("exit: Expression Syntax.\n");
            return (SUCCESS);
        }
    mputstr("exit\n");
    exit(mgetnbr(input[1]));
}
