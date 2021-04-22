/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** get_env
*/

#include "shell.h"

char **get_env(char **envp)
{
    char **new_env = NULL;
    int i = 0;

    while (envp[i] != NULL)
        i++;
    if ((new_env = malloc(sizeof(char *) * (i + 1))) == NULL)
        return (NULL);
    for (int j = 0; j != i; j++) {
        new_env[j] = malloc(sizeof(char) * (my_strlen(envp[j]) + 1));
        if (new_env[j] == NULL)
            return (NULL);
        new_env[j] = my_strcpy(new_env[j], envp[j]);
    }
    new_env[i] = NULL;
    return (new_env);
}