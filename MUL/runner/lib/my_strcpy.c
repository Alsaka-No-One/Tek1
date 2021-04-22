/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** Copy a string into another
*/

#include "include/function.h"

char *my_strcpy(char *src, char *dest)
{
    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[my_strlen(src) + 1] = '\0';
    return (dest);
}
