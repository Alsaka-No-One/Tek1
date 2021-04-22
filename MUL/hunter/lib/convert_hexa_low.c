/*
** EPITECH PROJECT, 2018
** Printf | convert_hexa
** File description:
** A function that convert dec in hexa
*/

#include "include/function.h"

int conversion_in_lowcase(int rest)
{
    if (rest >= 10 && rest <= 15)
        rest = rest + 87;
    else if(rest >= 0 && rest <= 9)
        rest = rest + 48;
    return (rest);
}

char *convert_hexa_low(int nb)
{
    char *str = malloc(sizeof(char) * 4);
    int rest;
    int i = 0;

    while (nb != 0) {
        rest = nb % 16;
        nb = nb / 16;
        rest = conversion_in_lowcase(rest);
        str[i] = rest;
        i++;
    }
    i++;
    str[i] = '\0';
    str = my_revstr(str);
    my_putstr(str);
    return (str);
}
