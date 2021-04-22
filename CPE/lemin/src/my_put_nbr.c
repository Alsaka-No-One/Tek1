/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** my_put_nbr
*/

#include <unistd.h>

void display_my_put_nbr(int i, int nb_modified, int divisor, int nb)
{
    char nb_char = 0;

    if (nb < 0) {
        nb_modified = nb * -1;
        write (1, "-", 1);
    }
    while (nb_modified >= divisor) {
        divisor = divisor * 10;
        i++;
    }
    while (i != 0) {
        divisor = divisor / 10;
        nb_char = nb_modified / divisor + '0';
        write(1, &nb_char, 1);
        nb_modified = nb_modified % divisor;
        i--;
    }
    nb_char = nb_modified % 10 + '0';
    write(1, &nb_char, 1);
}

int my_put_nbr(int nb)
{
    int nb_modified;
    int i;
    int divisor;

    i = 0;
    divisor = 10;
    nb_modified = nb;
    display_my_put_nbr(i, nb_modified, divisor, nb);
    return (0);
}
