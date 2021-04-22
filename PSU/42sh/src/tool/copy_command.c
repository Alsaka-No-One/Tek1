/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** copy_command
*/

#include <stdio.h>
#include <stdlib.h>

char *copy_command(char *str, int start)
{
    int size = start;
    char *new = NULL;

    for ( ; str[size] != '\0' && str[size] != '<' && str[size] != '>'
    && str[size] != '|' && str[size] != '&' && str[size] != ';'; size++);
    size -= start;
    new = malloc(sizeof(char) * (size + 1));
    if (new == NULL)
        return (NULL);
    new[size] = '\0';
    for (int i = 0 ; i < size ; i++)
        new[i] = str[i + start];
    return (new);
}