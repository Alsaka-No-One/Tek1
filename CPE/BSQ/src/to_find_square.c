/*
** EPITECH PROJECT, 2018
** CPE BSQ | to find square
** File description:
** Some functions to find the biggest square
*/

#include "../include/bsq.h"

int **transform(int **map, int nb_linum, int nb_cols)
{
    for (int cp_linum = 0; cp_linum < nb_linum; cp_linum++) {
        if (map[cp_linum][0] != 'o')
            map[cp_linum][0] = 2;
        else
            map[cp_linum][0] = 1;
    }
    for (int i = 1; i < nb_cols; i++) {
        if (map[0][i] != 'o')
            map[0][i] = 2;
        else
            map[0][i] = 1;
    }
    return (map);
}

int **modif_tab_into_dem(int **map, int nb_linum, int nb_cols)
{
    int linum = 1;
    int cols = 1;

    map = transform(map, nb_linum, nb_cols);
    while (linum < nb_linum) {
        if (map[linum][cols] == 'o')
            map[linum][cols] = 1;
        else
            map[linum][cols] = reverse_minesweeper(map, linum, cols, nb_cols);
        if (cols == nb_cols) {
            cols = 0;
            linum++;
        }
        cols++;
    }
    return (map);
}

int reverse_minesweeper(int **map, int linum, int cols, int nb_cols)
{
    int nb;
    int nb2;
    int one = map[linum - 1][cols - 1];
    int two = map[linum - 1][cols];
    int three = map[linum][cols - 1];

    if (one <= two)
        nb = one;
    else
        nb = two;
    if (two <= three)
        nb2 = two;
    else
        nb2 = three;
    if (nb > nb2)
        nb = nb2;
    return (nb + 1);
}
