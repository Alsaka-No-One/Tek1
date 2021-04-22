/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** A function that reverse a string
*/

#include "include/function.h"

char *my_revstr(char *str)
{
    char *dest = malloc(sizeof(char) * my_strlen(str));
    int i = 0;
    int j = 0;

    while (str[i] != '\0')
        i++;
    i--;
    while (i >= 0) {
        dest[j] = str[i];
        j++;
        i--;
    }
    dest[j] = '\0';
    return (dest);
}
