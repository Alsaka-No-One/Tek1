/*
** EPITECH PROJECT, 2018
** Printf | convert_binary
** File description:
** A function that convert dec in binary
*/

#include "../include/function.h"

int conversion_for_binary(int rest)
{
    if(rest >= 0 && rest <= 1)
        rest = rest + 48;
    return (rest);
}

char *convert_binary(int nb)
{
    char *str = malloc(sizeof(char) * 4);
    int rest;
    int i = 0;

    while (nb != 0) {
        rest = nb % 2;
        nb = nb / 2;
        rest = conversion_for_binary(rest);
        str[i] = rest;
        i++;
    }
    i++;
    str[i] = '\0';
    str = my_revstr(str);
    my_putstr(str);
    return (str);
}
