/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "../include/function.h"

long my_put_nbr_long(long nb)
{
    long rest = 0;
    long size = nb;
    long counter = 1;
    long nb_bis = 2147483648;

    if (nb < 0 && nb != -2147483648) {
        nb = -1 * nb;
        size = -1 * size;
        my_putchar ('-');
    }
    if (nb == 0)
        my_putchar('0');
    if (nb == -2147483648) {
        my_putchar('-');
        counter = 1000000000;
        while (counter > 0) {
            rest = nb_bis /counter + 48;
            my_putchar (rest);
            nb_bis = nb_bis % counter;
            counter = counter / 10;
        }
    } else {
        while (size >= 1) {
            counter = counter * 10;
            size = size / 10;
        }
        counter = counter / 10;
        while (counter > 0) {
            rest = nb / counter + 48;
            my_putchar (rest);
            nb = nb % counter;
            counter = counter / 10;
        }
    }
    return (0);
}
