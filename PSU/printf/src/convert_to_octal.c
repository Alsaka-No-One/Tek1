/*
** EPITECH PROJECT, 2018
** Printf | convert_to_oct
** File description:
** A function that convert dec in octal
*/

#include "../include/function.h"

int conversion_for_octal(int rest)
{
    if(rest >= 0 && rest <= 7)
        rest = rest + 48;
    return (rest);
}

char *convert_to_octal(int nb)
{
    char *str = malloc(sizeof(char) * 4);
    int rest;
    int i = 0;

    while (nb != 0) {
        rest = nb % 8;
        nb = nb / 8;
        rest = conversion_for_octal(rest);
        str[i] = rest;
        i++;
    }
    i++;
    str[i] = '\0';
    str = my_revstr(str);
    my_putstr(str);
    return (str);
}
