/*
** EPITECH PROJECT, 2018
** CPE BSQ | coord_square
** File description:
** The functions to take the coords of the biggest square
*/

#include "../include/bsq.h"

int get_the_biggest_number(int **map, int nb_linum, int nb_cols)
{
    int nb = map[0][0];
    int linum = 0;
    int cols = 1;

    while (linum < nb_linum) {
        if (map[linum][cols] > nb)
            nb = map[linum][cols];
        if (cols == nb_cols) {
            cols = 0;
            linum++;
        }
        cols++;
    }
    nb = nb - 1;
    return (nb);
}

int get_the_linum(int **map, int nb_linum, int nb_cols, int nb)
{
    int linum = 0;
    int cols = 0;

    while (map[linum][cols] != nb + 1) {
        if (cols == nb_cols) {
            cols = 0;
            linum++;
        }
        cols++;
    }
    return (linum);
}

int get_the_cols(int **map, int nb_linum, int nb_cols, int nb)
{
    int linum = 0;
    int cols = 0;

    while (map[linum][cols] != nb + 1) {
        if (cols == nb_cols) {
            cols = 0;
            linum++;
        }
        cols++;
    }
    return (cols);
}
