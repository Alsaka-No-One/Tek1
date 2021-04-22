/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** env
*/

#include "shell.h"

int make_env(char **arg, char ***envp)
{
    (void)arg;
    for (int i = 0; (*envp)[i] != NULL; i++) {
        my_putstr((*envp)[i]);
        my_putstr("\n");
    }
    return (SUCCESS);
}