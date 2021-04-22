/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** tetriminos_fall
*/

#include "mlib.h"
#include "tetris.h"
#include "data.h"
#include <stdlib.h>
#include <time.h>

static int fill_new_shape(tetriminos_t *tetri)
{
    tetri->mv_shape = malloc(sizeof(char *) * (tetri->height + 1));
    if (tetri->mv_shape == NULL)
        return (ERROR);
    tetri->mv_shape[tetri->height] = NULL;
    for (int i = 0; tetri->shape[i] != NULL; i++) {
        tetri->mv_shape[i] = mstr_cln(tetri->shape[i]);
        if (tetri->mv_shape[i] == NULL)
            return (ERROR);
    }
    return (SUCCESS);
}

static int new_tetriminos(data_t *data)
{
    int tetri = 0;

    srand(time(NULL));
    if (data->next < 0) {
        data->next = rand() % (data->nb_tetriminos - 1);
        if (data->tetriminos[data->next].error == true) {
            data->next = -1;
            return (ERROR);
        }
        tetri = rand() % (data->nb_tetriminos - 1);
        if (data->next < 0 || tetri < 0)
            return (ERROR);
        return (tetri);
    } else {
        tetri = data->next;
        data->next = rand() % (data->nb_tetriminos - 1);
        if (data->next < 0 || tetri < 0)
            return (ERROR);
        return (tetri);
    }
    return (ERROR);
}

int start_tetriminos(char **map, data_t *data, int *i)
{
    int pos_x = 0;
    int pos_y = 0;

    *i = new_tetriminos(data);
    if (*i == ERROR || data->tetriminos[*i].error == true)
        return (ERROR);
    data->pos_x = data->map_col - data->tetriminos[*i].width / 2;
    data->pos_y = 1;
    pos_x = data->pos_x;
    pos_y = data->pos_y;
    if (fill_new_shape(&data->tetriminos[*i]) == ERROR)
        return (ERROR);
    for (int j = 0; data->tetriminos[*i].mv_shape[j] != NULL
        ; j++, pos_y++) {
        for (int k = 0; data->tetriminos[*i].mv_shape[j][k] != '\0'
            ; k++, pos_x++)
            map[pos_y][pos_x] = data->tetriminos[*i].mv_shape[j][k];
        pos_x = data->map_col - data->tetriminos[*i].width / 2;
    }
    return (SUCCESS);
}