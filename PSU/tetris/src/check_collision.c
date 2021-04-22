/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** check_collision
*/

#include "tetris.h"
#include "data.h"

int collision(data_t *data, tetriminos_t *tetri, int pos_x, int pos_y)
{
    int status = 0;

    for (int j = 0; tetri->mv_shape[j] != NULL ; j++, pos_y++) {
        for (int k = 0; tetri->mv_shape[j][k] != '\0' ; k++, pos_x++)
            (data->save_map[pos_y][pos_x] != ' ') ? status = 1 : 0;
        if (status != 0)
            return (ERROR);
        pos_x = data->pos_x;
    }
    return (SUCCESS);
}
