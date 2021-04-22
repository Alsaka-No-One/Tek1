/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** loose_game
*/

#include "tetris.h"
#include "data.h"

int loose_game(char **map, int fall, data_t *data, int i)
{
    int pos_x = data->map_col - data->tetriminos[i].width / 2;
    int pos_y = 1;

    if ((map[pos_y][pos_x] != ' ' || map[pos_y][pos_x + 1] != ' ') &&
        fall == 0)
        return (SUCCESS);
    return (ERROR);
}
