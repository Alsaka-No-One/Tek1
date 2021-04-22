/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** handle_mvt
*/

#include "tetris.h"
#include "data.h"
#include "ncurses.h"

int handle_evt(char **map, data_t *data, tetriminos_t *tetri)
{
    int command = 0;

    nodelay(stdscr, TRUE);
    command = getch();
    if (command == data->key_right)
        tetriminos_right(map, tetri, data);
    if (command == data->key_left)
        tetriminos_left(map, tetri, data);
    if (command == data->key_quit)
        return (ERROR);
    if (command == data->key_pause)
        my_pause(data);
    if (command == data->key_drop)
        drop_block(map, tetri, data);
    return (SUCCESS);
}