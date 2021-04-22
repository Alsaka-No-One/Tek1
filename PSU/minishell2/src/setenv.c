/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** setenv
*/

#include "shell.h"

static int show_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        my_putstr("\n");
    }
    return (SUCCESS);
}

static int remake_setenv(char **arg, char ***envp, int i)
{
    if (compt_array(arg) == 2) {
        free((*envp)[i]);
        (*envp)[i] = malloc(sizeof(char) * (my_strlen(arg[1]) + 2));
        if ((*envp)[i] == NULL)
            return (ERROR);
        (*envp)[i] = my_strcpy_env((*envp)[i], arg[1]);
    }
    if (compt_array(arg) == 3) {
        free((*envp)[i]);
        (*envp)[i] = malloc(sizeof(char) 
                * (my_strlen(arg[1]) + my_strlen(arg[2]) + 2));
        if ((*envp)[i] == NULL)
            return (ERROR);
        (*envp)[i] = my_strcpy_double((*envp)[i], arg[1], arg[2]);
    }
    return (SUCCESS);
}

static int my_setenv(char **arg, char ***envp)
{
    int i = 0;

    i = compt_array(*envp);
    *envp = my_realloc(*envp);
    if (compt_array(arg) == 2) {
        (*envp)[i] = malloc(sizeof(char) * (my_strlen(arg[1]) + 2));
        if ((*envp)[i] == NULL)
            return (ERROR);
        (*envp)[i] = my_strcpy_env((*envp)[i], arg[1]);
    }
    if (compt_array(arg) == 3) {
        (*envp)[i] = malloc(sizeof(char)
                * (my_strlen(arg[1]) + my_strlen(arg[2]) + 2));
        if ((*envp)[i] == NULL)
            return (ERROR);
        (*envp)[i] = my_strcpy_double((*envp)[i], arg[1], arg[2]);
    }
    return (SUCCESS);
}

int make_setenv(char **arg, char ***envp)
{
    if (compt_array(arg) == 1)
        return (show_env(*envp));
    else if (compt_array(arg) > 3) {
        my_putstr("setenv: Too many arguments.\n");
        return (ERROR);
    }
    for (int i = 0; (*envp)[i] != NULL; i++)
        if (my_strcomp_env(arg[1], (*envp)[i]) == 1)
            return (remake_setenv(arg, envp, i));
    return (my_setenv(arg, envp));
}