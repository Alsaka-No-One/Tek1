/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** gameloop
*/

#include "tetris.h"
#include "data.h"
#include "mlib.h"
#include <ncurses.h>
#include <stdio.h>

static void init_game(void)
{
    initscr();
    keypad(stdscr, true);
}

//  the gameloop of the game
int gameloop(data_t *data)
{
    char **map = create_map(data);
    int loose_status = 0;

    data->save_map = create_map(data);
    if (map == NULL || data->save_map == NULL)
        return (ERROR);
    init_game();
    data->next = -1;
    while (loose_status != 1) {
        display_map(map, data);
        if (gameplay(map, data, &loose_status) == ERROR) {
            marr_free(map);
            return (ERROR);
        }
    }
    endwin();
    marr_free(map);
    return (SUCCESS);
}