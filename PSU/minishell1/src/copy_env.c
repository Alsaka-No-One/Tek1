/*
** EPITECH PROJECT, 2019
** PSU minishell 1 | copy env
** File description:
** The function that copy env
*/

#include "shell.h"
#include "function.h"

char **remalloc(char **tab)
{
    char **dest = NULL;
    int i = 0;

    while (tab[i] != NULL)
        i++;
    if ((dest = malloc(sizeof(char *) * (i + 2))) == NULL)
        return (NULL);
    for (int ii = 0; ii != i - 1; ii++) {
        if ((dest[ii] = malloc(sizeof(char) * my_strlen(tab[ii]) + 100)) == NULL)
            return (NULL);
        dest[ii] = my_strcpy(dest[ii], tab[ii]);
        dest[ii][my_strlen(tab[ii]) + 1] = '\0';
    }
    dest[i] = NULL;
    return (dest);
}