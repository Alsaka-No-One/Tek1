/*
** EPITECH PROJECT, 2019
** Tetris
** File description:
** File verfication
*/

#include "tetris.h"

bool is_tetrimino(char *name)
{
    int i = 0;

    if (!name)
        return (false);
    for ( ; name[i] ; i++);
    for ( ; i >= 0 && name[i] != '.' ; i--);
    if (i < 0)
        return (false);
    if (name[i + 0] == '.' && name[i + 1] == 't' &&
        name[i + 2] == 'e' && name[i + 3] == 't' &&
        name[i + 4] == 'r' && name[i + 5] == 'i' &&
        name[i + 6] == 'm' && name[i + 7] == 'i' &&
        name[i + 8] == 'n' && name[i + 9] == 'o' &&
        !name[i + 10])
        return (true);
    return (false);
}
