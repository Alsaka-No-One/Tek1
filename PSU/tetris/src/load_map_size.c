/*
** EPITECH PROJECT, 2019
** Tetris
** File description:
** Load the map size from optarg
*/

#include "tetris.h"
#include "data.h"
#include "mlib.h"

void load_map_size(data_t *data, char *optarg)
{
    static int call = 0;

    if (call % 2 == 0)
        data->map_row = mgetnbr(optarg);
    if (call++ % 2 == 1)
        data->map_col = mgetnbr(optarg);
}
