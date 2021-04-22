/*
** EPITECH PROJECT, 2019
** Tetris
** File description:
** Data verification
*/

#include "tetris.h"
#include "data.h"
#include <ncurses.h>

static bool is_key(int key)
{
    if (key >= 'a' && key <= 'z')
        return (true);
    switch (key) {
    case KEY_UP:
        return (true);
    case KEY_DOWN:
        return (true);
    case KEY_RIGHT:
        return (true);
    case KEY_LEFT:
        return (true);
    case KEY_BACKSPACE:
        return (true);
    }
    return (false);
}

static int verif_key(data_t data)
{
    if (is_key(data.key_left) == false)
        return (ERROR);
    if (is_key(data.key_right) == false)
        return (ERROR);
    if (is_key(data.key_turn) == false)
        return (ERROR);
    if (is_key(data.key_drop) == false)
        return (ERROR);
    if (is_key(data.key_quit) == false)
        return (ERROR);
    if (is_key(data.key_pause) == false)
        return (ERROR);
    return (SUCCESS);
}

static int verif_option(data_t data)
{
    if (data.level <= 0)
        return (ERROR);
    if (data.map_row <= 0)
        return (ERROR);
    if (data.map_col <= 0)
        return (ERROR);
    return (SUCCESS);
}

int data_verif(data_t data)
{
    if (verif_key(data) == ERROR)
        return (ERROR);
    if (verif_option(data) == ERROR)
        return (ERROR);
    return (SUCCESS);
}
