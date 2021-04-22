/*
** EPITECH PROJECT, 2018
** Printf | convert_to_oct
** File description:
** A function that convert dec in octal
*/

#include "include/function.h"

int conversion_for_octal2(int rest)
{
    if(rest >= 0 && rest <= 7)
        rest = rest + 48;
    return (rest);
}

void adding_zero(int p)
{
    while (p != 3) {
        my_putchar('0');
        p++;
    }
}

char *convert_to_octal2(int nb)
{
    char *str = malloc(sizeof(char) * 4);
    int rest;
    int i = 0;
    int p;

    while (nb != 0) {
        rest = nb % 8;
        nb = nb / 8;
        rest = conversion_for_octal2(rest);
        str[i] = rest;
        i++;
    }
    i++;
    str[i] = '\0';
    str = my_revstr(str);
    p = my_strlen(str);
    adding_zero(p);
    my_putstr(str);
    return (str);
}
