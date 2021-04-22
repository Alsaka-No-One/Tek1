/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** *
*/

#include "shell.h"

char **string_to_arg2(char **arg, int i_tab, int j_tab)
{
    arg[i_tab][j_tab] = '\0';
    arg[i_tab + 1] = NULL;
    return (arg);
}