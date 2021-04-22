/*
** EPITECH PROJECT, 2018
** CPE BSQ | create tab rev dem
** File description:
** Functions that transform a char ** into an int **
*/

#include "../include/bsq.h"

int **create_tab_rev_dem(char **src, int nb_linum, int nb_cols, int **dest)
{
    int linum = 0;
    int cols = 0;

    dest = malloc(sizeof(int *) * ((nb_linum + 3) * (nb_cols + 3)));
    if (dest == NULL)
        exit(84);
    for (int i = 0; i < nb_linum + 10; i++) {
        dest[i] = malloc(sizeof(int) * (nb_cols + 5));
        dest[i][nb_cols + 1] = -10;
    }
    while (linum < nb_linum) {
        if (src[linum][cols] == '\0') {
            cols = 0;
            linum++;
        }
        dest[linum][cols] = src[linum][cols];
        cols++;
    }
    return (dest);
}

void print_int_tab(int **map, int nb_linum, int nb_cols)
{
    int linum = 0;
    int i = 0;

    while (linum < nb_linum) {
        if (map[linum][i] == '.' || map[linum][i] == 'o')
            my_putchar(map[linum][i]);
        else
            my_printf("%d", map[linum][i]);
        i++;
        if (i == nb_cols) {
            my_putchar('\n');
            linum++;
            i = 0;
        }
    }
}
