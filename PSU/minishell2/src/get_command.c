/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** get_command
*/

#include "shell.h"

int get_command(func_t *tab, char **arg, char ***envp)
{
    int i = 0;

    for (; i != 4; i++) {
        if (my_strcomp(arg[0], tab[i].name) == 1) {
            (tab[i].fptr) (arg, envp);
            break;
        }
    }
    if (i == 4)
        if (analyse_exec(arg, *envp) == ERROR)
            return (display_invalid_command(arg));
    return (SUCCESS);
}