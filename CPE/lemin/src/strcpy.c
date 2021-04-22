/*
** EPITECH PROJECT, 2019
** str function
** File description:
** The function include str
*/

#include "lemin.h"

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
