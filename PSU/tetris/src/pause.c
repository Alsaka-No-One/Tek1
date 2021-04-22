/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** pause
*/

#include "tetris.h"
#include "data.h"
#include <ncurses.h>

void my_pause(data_t *data)
{
    static int status = 0;

    nodelay(stdscr, TRUE);
    while (status == 0)
        if (getch() == data->key_pause)
            status = 1;
}