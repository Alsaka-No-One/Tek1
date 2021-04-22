/*
** EPITECH PROJECT, 2018
** PSU my_sokoban | direction
** File description:
** The functions that will change the direction
*/

#include "../include/sokoban.h"

void moove_down(char **map, coord_t *coord)
{
    char cover = map[coord->p_linum + 1][coord->p_cols];
    char box = map[coord->p_linum + 1][coord->p_cols];
    int linum = coord->p_linum + 1;

    if (linum < coord->linum) {
        map[coord->p_linum][coord->p_cols] = ' ';
        coord->p_linum += 1;
        map[coord->p_linum][coord->p_cols] = 'P';
        if (cover == '#') {
            map[coord->p_linum][coord->p_cols] = '#';
            coord->p_linum -= 1;
            map[coord->p_linum][coord->p_cols] = 'P';
        }
        else
            check_box_down(map, coord, box);
    }
}

void moove_up(char **map, coord_t *coord)
{
    char cover = map[coord->p_linum - 1][coord->p_cols];
    char box = map[coord->p_linum - 1][coord->p_cols];
    int linum = coord->p_linum - 1;

    if (linum > 0) {
        map[coord->p_linum][coord->p_cols] = ' ';
        coord->p_linum -= 1;
        map[coord->p_linum][coord->p_cols] = 'P';
        if (cover == '#') {
            map[coord->p_linum][coord->p_cols] = '#';
            coord->p_linum += 1;
            map[coord->p_linum][coord->p_cols] = 'P';
        }
        else
            check_box_up(map, coord, box);
    }
}

void moove_left(char **map, coord_t *coord)
{
    char cover = map[coord->p_linum][coord->p_cols - 1];
    char box = map[coord->p_linum][coord->p_cols - 1];
    int cols = coord->p_cols - 1;

    if (cols > 0){
        map[coord->p_linum][coord->p_cols] = ' ';
        coord->p_cols -= 1;
        map[coord->p_linum][coord->p_cols] = 'P';
        if (cover == '#') {
            map[coord->p_linum][coord->p_cols] = '#';
            coord->p_cols += 1;
            map[coord->p_linum][coord->p_cols] = 'P';
        }
        else
            check_box_left(map, coord, box);
    }
}

void moove_right(char **map, coord_t *coord)
{
    char cover = map[coord->p_linum][coord->p_cols + 1];
    char box = map[coord->p_linum][coord->p_cols + 1];
    int cols = coord->p_cols + 1;

    if (cols < coord->cols) {
        map[coord->p_linum][coord->p_cols] = ' ';
        coord->p_cols += 1;
        map[coord->p_linum][coord->p_cols] = 'P';
        if (cover == '#') {
            map[coord->p_linum][coord->p_cols] = '#';
            coord->p_cols -= 1;
            map[coord->p_linum][coord->p_cols] = 'P';
        }
        else
            check_box_right(map, coord, box);
    }
}

void get_mvt_player(char **map, coord_t *coord, char **initial_map)
{
    int d = getch();

    switch(d) {
    case KEY_UP:
        moove_up(map, coord);
        break;
    case KEY_RIGHT:
        moove_right(map, coord);
        break;
    case KEY_DOWN:
        moove_down(map, coord);
        break;
    case KEY_LEFT:
        moove_left(map, coord);
        break;
    case ' ':
        map = reset_map(map, initial_map, coord);
        break;
    }
    refresh();
}
