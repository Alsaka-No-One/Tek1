/*
** EPITECH PROJECT, 2018
** my_put_nbr_long
** File description:
** A function that display a long number
*/

#include "include/function.h"

int conversion_to_long(int rest)
{
    if (rest >= 0 && rest <= 9)
        rest = rest + 48;
    return (rest);
}

char *my_put_nbr_long(long nb)
{
    char *str = malloc(sizeof(char) * 4);
    long rest;
    long i = 0;

    while (nb != 0) {
        rest = nb % 10;
        nb = nb / 10;
        rest = conversion_to_long(rest);
        str[i] = rest;
        i++;
    }
    i++;
    str[i] = '\0';
    str = my_revstr(str);
    my_putstr(str);
    return (str);
}
