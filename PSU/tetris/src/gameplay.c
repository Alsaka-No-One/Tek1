/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** gameplay
*/

#include "mlib.h"
#include "tetris.h"
#include "data.h"
#include "ncurses.h"

static void make_save(char **map, data_t *data)
{
    for (int i = 0; map[i] != NULL; i++)
        mstr_cp(map[i], data->save_map[i]);
}

int gameplay(char **map, data_t *data, int *loose_status)
{
    static int fall = 0;
    static int tetri = 0;

    if (fall == 0) {
        line_correct(map, data);
        make_save(map, data);
        if (start_tetriminos(map, data, &tetri) != ERROR)
            fall = 1;
    } else {
        tetriminos_fall(data, &fall, &data->tetriminos[tetri], map);
        if (handle_evt(map, data, &data->tetriminos[tetri]) == ERROR)
            *loose_status = 1;
        if (loose_game(map, fall, data, tetri) == SUCCESS)
            *loose_status = 1;
    }
    return (SUCCESS);
}