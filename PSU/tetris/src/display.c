/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** display
*/

#include "tetris.h"
#include "data.h"
#include <ncurses.h>
#include <unistd.h>

void display_map(char **map, data_t *data)
{
    int line = LINES / 2 - data->map_row / 2;
    int cols = COLS / 2 - data->map_col;
    int time_cols = COLS / 2 - data->map_col * 3;
    int time_line = LINES / 2 + data->map_row / 2;

    clear();
    mvprintw(time_line - 5, time_cols, "timer:");
    print_clock(time_cols + 7, time_line - 5);
    for (int i = 0; map[i] != NULL; i++, line++)
        mvprintw(line, cols, "%s\n", map[i]);
    refresh();
    usleep(50000);
}