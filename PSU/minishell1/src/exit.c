/*
** EPITECH PROJECT, 2019
** PSU exit
** File description:
** The exit function
*/

#include "function.h"
#include "shell.h"

int my_exit(char **arg)
{
    int nb_return = 0;

    if (arg[1]) {
        nb_return = my_getnbr(arg[1]);
        my_putstr("exit\n");
        return (nb_return);
    }
    else
        my_putstr("exit\n");
    return (0);
}