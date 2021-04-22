/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** usefull_function2
*/

#include "shell.h"

int my_strcomp_env(char const *str, char const *str_comp)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        if (str[i] != str_comp[i])
            return (-1);
    return (1);
}

int compt_array(char **array)
{
    int i = 0;

    while (array[i] != NULL)
        i++;
    return (i);
}