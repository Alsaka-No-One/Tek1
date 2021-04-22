/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** analyse_exec
*/

#include "shell.h"

int analyse_exec(char **arg, char **envp)
{
    if (access(arg[0], F_OK) != 0)
        return (find_path(arg, envp));
    return (my_exec(arg, envp));
}