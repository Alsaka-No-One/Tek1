/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** arg_gestion
*/

#include "shell.h"

int arg_gestion(int argc, char **argv, char **envp)
{
    if (argc != 1)
        return (ERROR);
    (void)argv;
    return (minishell(envp));
}