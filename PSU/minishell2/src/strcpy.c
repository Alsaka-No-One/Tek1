/*
** EPITECH PROJECT, 2019
** str function
** File description:
** The function include str
*/

#include "shell.h"

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

char *my_strcpy_env(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '=';
    dest[i + 1] = '\0';
    return (dest);
}

char *my_strcpy_double(char *dest, char *src, char *second)
{
    int i = 0;
    int j = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '=';
    i++;
    while (second[j] != '\0') {
        dest[i] = second[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}