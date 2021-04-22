/*
** EPITECH PROJECT, 2019
** Tetris
** File description:
** Data error gestion
*/

#include "tetris.h"
#include "data.h"

static bool verif_char(char *shape)
{
    int nb_star = 0;

    for (int ii = 0 ; shape[ii] ; ii++) {
        if (shape[ii] == '*')
            nb_star++;
        if (shape[ii] != '*' &&
            shape[ii] != ' ')
            return (false);
    }
    if (nb_star == 0)
        return (false);
    return (true);
}

bool error_shape(tetriminos_t tetriminos)
{
    for (int i = 0 ; tetriminos.shape[i] ; i++)
        if (verif_char(tetriminos.shape[i]) == false)
            return (true);
    return (false);
}

bool error_first_line(data_t data, tetriminos_t tetriminos)
{
    if (tetriminos.width <= 0 || tetriminos.width > data.map_row)
        return (true);
    if (tetriminos.height <= 0 || tetriminos.height > data.map_col)
        return (true);
    if (tetriminos.color < 0)
        return (true);
    return (false);
}
