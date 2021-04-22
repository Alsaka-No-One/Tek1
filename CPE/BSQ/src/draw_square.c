/*
** EPITECH PROJECT, 2018
** CPE BSQ | draw_square
** File description:
** The function that draw the square
*/

#include "../include/bsq.h"

char **draw_the_square(char **tab, int linum, int cols, int nb)
{
    int x = cols - (nb - 1);
    int y = linum - (nb - 1);
    int i = 0;

    if (x < 0 || y < 0)
        exit(84);
    while (i < (nb * nb)) {
        if (x == cols + 1) {
            x = cols - (nb - 1);
            y++;
        }
        tab[y][x] = 'x';
        i++;
        x++;
    }
    return (tab);
}
