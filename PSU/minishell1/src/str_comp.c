/*
** EPITECH PROJECT, 2019
** PSU minishell1 | str_comp
** File description:
** The function to compare 2 strings
*/

#include "function.h"
#include "shell.h"

char **str_in_tab(char *str)
{
    char **tab = NULL;
    int ii = 0;
    int j = 0;
    int j_tab = 0;

    if ((tab = malloc(sizeof(char *) * 2)) == NULL)
        return (NULL);
    for (int i = 0; i != 2; i++)
        if ((tab[i] = malloc(sizeof(char) * 100)) == NULL)
            return (NULL);
    while (str[j] != '\0') {
        tab[ii][j_tab] = str[j];
        if (str[j + 1] == ' ') {
            j_tab = 0;
            ii++;
            j++;
        }
        j++;
        j_tab++;
    }
    return (tab);
}

int str_comp(char *str, char *strc)
{
    int i = 0;

    while(str[i] != '\0') {
        if (str[i] == strc[i])
            i++;
        else
            return (-1);
    }
    if (i == my_strlen(strc))
        return (0);
    else 
        return (-1);
}