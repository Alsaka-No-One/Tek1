/*
** EPITECH PROJECT, 2018
** Kaminari - MyLibC | My Put Number
** File description:
** A function that displays a number
*/

#include "mylibc.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb <= 9)
        my_putchar(nb + '0');
    else if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return (nb);
}
