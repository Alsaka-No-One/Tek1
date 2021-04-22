/*
** EPITECH PROJECT, 2018
** PSU my_sokoban | direction box
** File description:
** The function to move box
*/

#include "../include/sokoban.h"

void check_box_up(char **map, coord_t *coord, char box)
{
    char cover = map[coord->p_linum - 1][coord->p_cols];

    if (box == 'X') {
        map[coord->p_linum][coord->p_cols] = ' ';
        map[coord->p_linum][coord->p_cols] = 'P';
        map[coord->p_linum - 1][coord->p_cols] = 'X';
    }
    if (cover == '#' && box == 'X') {
        map[coord->p_linum - 1][coord->p_cols] = '#';
        map[coord->p_linum][coord->p_cols] = 'X';
        coord->p_linum += 1;
        map[coord->p_linum][coord->p_cols] = 'P';
    }
    if (cover == 'X' && box == 'X') {
        map[coord->p_linum - 1][coord->p_cols] = 'X';
        map[coord->p_linum][coord->p_cols] = 'X';
        coord->p_linum += 1;
        map[coord->p_linum][coord->p_cols] = 'P';
    }
}

void check_box_down(char **map, coord_t *coord, char box)
{
    char cover = map[coord->p_linum + 1][coord->p_cols];

    if (box == 'X') {
        map[coord->p_linum][coord->p_cols] = ' ';
        map[coord->p_linum][coord->p_cols] = 'P';
        map[coord->p_linum + 1][coord->p_cols] = 'X';
    }
    if (cover == '#' && box == 'X') {
        map[coord->p_linum + 1][coord->p_cols] = '#';
        map[coord->p_linum][coord->p_cols] = 'X';
        coord->p_linum -= 1;
        map[coord->p_linum][coord->p_cols] = 'P';
    }
    if (cover == 'X' && box == 'X') {
        map[coord->p_linum + 1][coord->p_cols] = 'X';
        map[coord->p_linum][coord->p_cols] = 'X';
        coord->p_linum -= 1;
        map[coord->p_linum][coord->p_cols] = 'P';
    }
}

void check_box_right(char **map, coord_t *coord, char box)
{
    char cover = map[coord->p_linum][coord->p_cols + 1];

    if (box == 'X') {
        map[coord->p_linum][coord->p_cols] = ' ';
        map[coord->p_linum][coord->p_cols] = 'P';
        map[coord->p_linum][coord->p_cols + 1] = 'X';
    }
    if (cover == '#' && box == 'X') {
        map[coord->p_linum][coord->p_cols + 1] = '#';
        map[coord->p_linum][coord->p_cols] = 'X';
        coord->p_cols -= 1;
        map[coord->p_linum][coord->p_cols] = 'P';
    }
    if (cover == 'X' && box == 'X') {
        map[coord->p_linum][coord->p_cols + 1] = 'X';
        map[coord->p_linum][coord->p_cols] = 'X';
        coord->p_cols -= 1;
        map[coord->p_linum][coord->p_cols] = 'P';
    }
}

void check_box_left(char **map, coord_t *coord, char box)
{
    char cover = map[coord->p_linum][coord->p_cols - 1];

    if (box == 'X') {
        map[coord->p_linum][coord->p_cols] = ' ';
        map[coord->p_linum][coord->p_cols] = 'P';
        map[coord->p_linum][coord->p_cols - 1] = 'X';
    }
    if (cover == '#' && box == 'X') {
        map[coord->p_linum][coord->p_cols - 1] = '#';
        map[coord->p_linum][coord->p_cols] = 'X';
        coord->p_cols += 1;
        map[coord->p_linum][coord->p_cols] = 'P';
    }
    if (cover == 'X' && box == 'X') {
        map[coord->p_linum][coord->p_cols - 1] = 'X';
        map[coord->p_linum][coord->p_cols] = 'X';
        coord->p_cols += 1;
        map[coord->p_linum][coord->p_cols] = 'P';
    }
}
