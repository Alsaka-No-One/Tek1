/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** A function that print a number
*/

#include "include/function.h"

int conversion_for_decimal(int rest)
{
    if (rest >= 0 && rest <= 9)
        rest = rest + 48;
    return (rest);
}

char *my_put_nbr(int nb)
{
    char *str = malloc(sizeof(char) * 4);
    int rest;
    int i = 0;

    while (nb != 0) {
        rest = nb % 10;
        nb = nb / 10;
        rest = conversion_for_decimal(rest);
        str[i] = rest;
        i++;
    }
    i++;
    str[i] = '\0';
    str = my_revstr(str);
    return(str);
}
