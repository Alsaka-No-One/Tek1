/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** display_invalid_command
*/

#include "shell.h"

int display_invalid_command(char **arg)
{
    my_putstr(arg[0]);
    my_putstr(": Command not found.\n");
    return (SUCCESS);
}