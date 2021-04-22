/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** my_exit
*/

#include "shell.h"

int my_exit(char **arg)
{
    if (arg[1]) {
        my_putstr("exit\n");
        return (my_getnbr(arg[1]));
    }
    my_putstr("exit\n");
    return (SUCCESS);
}