/*
** EPITECH PROJECT, 2019
** Tetris
** File description:
** Load the tetriminos into data struct
*/

#include "tetris.h"
#include "data.h"

int load_tetriminos(data_t *data)
{
    data->tetriminos = alloc_tetriminos(data);
    if (!data->tetriminos)
        return (ERROR);
    if (fill_tetriminos(data) == ERROR)
        return (ERROR);
    return (SUCCESS);
}
