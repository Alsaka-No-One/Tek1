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

int my_put_nbr(int nb)
{
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    } else
        my_putchar(nb + 48);
}