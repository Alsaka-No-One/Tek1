/*
** EPITECH PROJECT, 2019
** str function
** File description:
** The function include str
*/

#include "include/function.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_strcpy(char *dest, char *src)
{
    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    return (dest);
}