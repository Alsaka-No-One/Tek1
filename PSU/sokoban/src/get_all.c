/*
** EPITECH PROJECT, 2018
** PSU my_sokoban | get_all
** File description:
** The function to take all coordinates
*/

#include "../include/sokoban.h"

coord_t *check_p(char *buffer, char **map, coord_t *coord)
{
    int i = 0;

    check_nbr_p(buffer);
    while (buffer[i] != '\0') {
        if (buffer[i] == 'P') {
            coord = get_p(map, coord);
            return (coord);
        }
        i++;
    }
}

coord_t *get_p(char **map, coord_t *coord)
{
    int linum = 0;
    int cols = 0;

    while (map[linum][cols] != 'P') {
        if (cols == coord->cols) {
            cols = 0;
            linum++;
        }
        cols++;
    }
    coord->p_linum = linum;
    coord->p_cols = cols;
    return (coord);
}

void check_nbr_xo(char *buffer)
{
    int x = 0;
    int o = 0;
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == 'X')
            x++;
        else if (buffer[i] == 'O')
            o++;
        i++;
    }
    if (x != o) {
        my_putstr("Invalid map: not the same number of 'X' and 'O'!\n");
        exit(84);
    }
}

void check_nbr_p(char *buffer)
{
    int p = 0;
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == 'P')
            p++;
        i++;
    }
    if (p != 1) {
        my_putstr("Invalid number of player!\n");
        exit(84);
    }
}
