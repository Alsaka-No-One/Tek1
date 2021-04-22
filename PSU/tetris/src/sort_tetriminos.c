/*
** EPITECH PROJECT, 2019
** Tetris
** File description:
** Sort the tetriminos by name
*/

#include "tetris.h"
#include "data.h"
#include "mlib.h"

static void invert_case(int *isort, int i, int ii)
{
    int temp = isort[i];

    isort[i] = isort[ii];
    isort[ii] = temp;
}

static void sort_tetrimino(int *isort, tetriminos_t *tetriminos, int t)
{
    for (int i = 0 ; i < t - 1 ; i++)
        if (mstrcmp(tetriminos[isort[i]].name,
            tetriminos[isort[i + 1]].name) > 0) {
            invert_case(isort, i, i + 1);
            break;
        }
}

static bool is_sorted(int *isort, tetriminos_t *tetriminos, int t)
{
    for (int i = 0 ; i < t - 1 ; i++)
        if (mstrcmp(tetriminos[isort[i]].name,
            tetriminos[isort[i + 1]].name) > 0)
            return (false);
    return (true);
}

void sort_tetriminos(int *isort, tetriminos_t *tetriminos, int t)
{
    for (int i = 0 ; i < t ; i++)
        isort[i] = i;
    while (is_sorted(isort, tetriminos, t) == false)
        sort_tetrimino(isort, tetriminos, t);
}
