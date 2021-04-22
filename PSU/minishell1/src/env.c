/*
** EPITECH PROJECT, 2019
** PSU minishell1 | env
** File description:
** The function realated to the env
*/

#include "function.h"
#include "shell.h"

char **set_env(char **env, char **arg)
{
    if (!arg[1])
        print_env(env, arg);
    return (env);
}

char **print_env(char **env, char **arg)
{
    if (arg[1])
        return (env);
    for (int i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
    return (env);
}