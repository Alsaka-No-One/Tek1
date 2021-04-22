/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** cd
*/

#include "shell.h"

int make_cd(char **arg, char ***envp)
{
    (void)arg;
    (void)envp;
    my_putstr("cd c'est moi^^\n");
    return (SUCCESS);
}