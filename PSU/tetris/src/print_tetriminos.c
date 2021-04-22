/*
** EPITECH PROJECT, 2019
** Tetris
** File description:
** Print the tetriminos for the debug
*/

#include <stdlib.h>
#include "tetris.h"
#include "data.h"
#include "mlib.h"

static void print_size_color(tetriminos_t tetriminos)
{
    mputstr(" : Size ");
    mputnbr(tetriminos.width);
    mputchar('*');
    mputnbr(tetriminos.height);
    mputstr(" : Color ");
    mputnbr(tetriminos.color);
    mputstr(" :\n");
}

static void print_tetrimino(tetriminos_t tetriminos)
{
    mputstr("Tetriminos : Name ");
    mputstr(tetriminos.name);
    if (tetriminos.error == true)
        mputstr(" : Error\n");
    else {
        print_size_color(tetriminos);
        mputarr(tetriminos.shape);
    }
}

int print_tetriminos(data_t data)
{
    int *isort = malloc(sizeof(int *) * data.nb_tetriminos);

    mputstr("Tetriminos : ");
    mputnbr(data.nb_tetriminos);
    mputchar('\n');
    if (!isort)
        return (ERROR);
    sort_tetriminos(isort, data.tetriminos, data.nb_tetriminos);
    for (int i = 0 ; i < data.nb_tetriminos ; i++)
        print_tetrimino(data.tetriminos[isort[i]]);
    return (SUCCESS);
}
