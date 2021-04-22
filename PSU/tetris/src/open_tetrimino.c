/*
** EPITECH PROJECT, 2019
** Tetris
** File description:
** Open a tetrimino file
*/

#include <stdlib.h>
#include <stdio.h>
#include "tetris.h"
#include "mlib.h"

int open_tetrimino(FILE **fp, char *name)
{
    char *tetrimino = mstr_cln("./tetriminos/");
    char *path = NULL;

    if (!tetrimino)
        return (ERROR);
    path = mstrcat(tetrimino, name);
    free(tetrimino);
    if (!path)
        return (ERROR);
    *fp = fopen(path, "r");
    free(path);
    if (*fp == NULL)
        return (ERROR);
    return (SUCCESS);
}
