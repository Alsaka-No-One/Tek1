/*
** EPITECH PROJECT, 2018
** Kaminari - MyLibC | My String Length
** File description:
** A function that counts the number of characters in a string
*/

#include "mylibc.h"

int my_strlen(char *str)
{
    char *s;

    if (str == NULL)
        return (0);
    for (s = str; *s; s++);
    return (s - str);
}
