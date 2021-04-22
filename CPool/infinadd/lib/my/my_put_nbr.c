/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** retry task 7 day 3
*/

int my_put_nbr(int nb)
{
    int i = 1;
    int size = nb;
    long result = 0;

    if (nb < 0 && nb > -2147483648) {
        nb = -1 * nb;
        size = -1 * size;
        my_putchar ('-');
    }
    if (nb == 0) {
        my_putchar (0 + 48);
    } else {
        while (size >= 1) {    
            i = i * 10;
            size = size / 10;
        }
        i = i / 10;
        while (i > 0) {
            result = nb / i + 48;
            my_putchar (result);
            nb = nb % i;
            i = i / 10;
        }
    }
    return (0);
}
