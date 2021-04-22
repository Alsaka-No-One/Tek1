/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** free_tab
*/

#include "shell.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}