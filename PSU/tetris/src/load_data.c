/*
** EPITECH PROJECT, 2019
** Tetris
** File description:
** Load the data_t struct
*/

#include "tetris.h"
#include "data.h"
#include <curses.h>

data_t load_data(void)
{
    data_t data;

    data.level = 1;
    data.key_left = KEY_LEFT;
    data.key_right = KEY_RIGHT;
    data.key_turn = KEY_UP;
    data.key_drop = KEY_DOWN;
    data.key_quit = 'q';
    data.key_pause = KEY_BACKSPACE;
    data.map_row = 20;
    data.map_col = 10;
    data.without_next = false;
    data.debug = false;
    return (data);
}
