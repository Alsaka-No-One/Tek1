/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** realloc
*/

#include "shell.h"

char **my_realloc(char **tab)
{
    char **new_tab = NULL;
    int i = 0;

    if ((new_tab = malloc(sizeof(char *) * (compt_array(tab) + 2))) == NULL)
        return (NULL);
    for (; tab[i] != NULL; i++) {
        new_tab[i] = malloc(sizeof(char) * (my_strlen(tab[i]) + 1));
        if (new_tab[i] == NULL)
            return (NULL);
        new_tab[i] = my_strcpy(new_tab[i], tab[i]);
    }
    new_tab[i] = NULL;
    new_tab[i + 1] = NULL;
    return (new_tab);
}