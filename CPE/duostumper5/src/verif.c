/*
** EPITECH PROJECT, 2019
** verif
** File description:
** verifications
*/

#include <stdio.h>
#include <stdlib.h>
#include "stumper.h"

void verifs(data_t *dat, char **arr, int col, int row)
{
    if (col < 0 || row < 0 || col >= dat->size || row >= dat->size)
        dat->pasta = 2;
    else if (arr[row + 1][col + 1] != ' ')
        dat->pasta = 2;
}
