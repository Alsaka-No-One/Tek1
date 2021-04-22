/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** tetriminos_mvt
*/

#include "mlib.h"
#include "tetris.h"
#include "data.h"
#include <unistd.h>
#include <stdlib.h>

void tetriminos_fall(data_t *data, int *fall, tetriminos_t *tetri, char **map)
{
    static int sleep = 100000;

    if (collision(data, tetri, data->pos_x, data->pos_y + 1) == ERROR) {
        *fall = 0;
        return;
    }
    for (int i = data->pos_x; i != tetri->width + data->pos_x; i++) {
        for (int j = data->pos_y + tetri->height - 1
            ; j != data->pos_y - 1; j--) {
            map[j + 1][i] = map[j][i];
            map[j][i] = ' ';
        }
    }
    data->pos_y += 1;
    usleep(sleep);
}

void tetriminos_right(char **map, tetriminos_t *tetri, data_t *data)
{
    if (collision(data, tetri, data->pos_x + 1, data->pos_y) == ERROR)
        return;
    for (int j = data->pos_y; j != data->pos_y + tetri->height; j++) {
        for (int i = data->pos_x + tetri->width - 1
            ; i != data->pos_x - 1; i--) {
            map[j][i + 1] = map[j][i];
            map[j][i] = ' ';
        }
    }
    data->pos_x += 1;
}

void tetriminos_left(char **map, tetriminos_t *tetri, data_t *data)
{
    int index = 0;

    if (collision(data, tetri, data->pos_x - 1, data->pos_y) == ERROR)
        return;
    for (int j = data->pos_y; j != data->pos_y + tetri->height; j++)
        for (int i = data->pos_x
            ; i != data->pos_x + tetri->width; i++, index++) {
            map[j][i - 1] = map[j][i];
            map[j][i] = ' ';
        }
    data->pos_x -= 1;
}

static void draw_for_drop(char **map, data_t *data, int i, tetriminos_t *tetri)
{
    for (int j = data->pos_y + tetri->height - 1
        ; j != data->pos_y - 1; j--) {
        map[j + 1][i] = map[j][i];
        map[j][i] = ' ';
    }
}

void drop_block(char **map, tetriminos_t *tetri, data_t *data)
{
    while (collision(data, tetri, data->pos_x, data->pos_y + 1) != ERROR) {
        for (int i = data->pos_x; i != tetri->width + data->pos_x; i++)
            draw_for_drop(map, data, i, tetri);
        data->pos_y += 1;
    }
    usleep(100000);
}