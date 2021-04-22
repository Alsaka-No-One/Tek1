/*
** EPITECH PROJECT, 2019
** stumper 3
** File description:
** write_number
*/

#include "stumper.h"

void write_0(char **map, char symbol, int *pos)
{
    int up = *pos + 1;
    int left = *pos;
    int right = *pos + 4;

    for (int i = 0; i != 3; i++, up++) {
        map[0][up] = symbol;
        map[4][up] = symbol;
    }
    for (int i = 1; i <= 3; i++) {
        map[i][left] = symbol;
        map[i][right] = symbol;
    }
}

void write_1(char **map, char symbol, int *pos)
{
    map[1][*pos] = symbol;
    map[0][*pos + 1] = symbol;
    map[4][*pos + 1] = symbol;
    map[4][*pos + 4] = symbol;
    for (int i = 0; i <= 4; i++) {
        map[i][*pos + 2] = symbol;
        map[i][*pos + 3] = symbol;
    }
}

void write_2(char **map, char symbol, int *pos)
{
    map[4][*pos] = symbol;
    map[4][*pos + 1] = symbol;
    map[4][*pos + 2] = symbol;
    map[4][*pos + 3] = symbol;
    map[4][*pos + 4] = symbol;
    map[1][*pos] = symbol;
    map[1][*pos + 4] = symbol;
    map[2][*pos + 3] = symbol;
    map[3][*pos + 1] = symbol;
    map[0][*pos + 1] = symbol;
    map[0][*pos + 2] = symbol;
    map[0][*pos + 3] = symbol;
}

void write_3(char **map, char symbol, int *pos)
{
    map[0][*pos] = symbol;
    map[0][*pos + 1] = symbol;
    map[0][*pos + 2] = symbol;
    map[0][*pos + 3] = symbol;
    map[4][*pos] = symbol;
    map[4][*pos + 1] = symbol;
    map[4][*pos + 2] = symbol;
    map[4][*pos + 3] = symbol;
    map[1][*pos + 4] = symbol;
    map[3][*pos + 4] = symbol;
    map[2][*pos + 1] = symbol;
    map[2][*pos + 2] = symbol;
    map[2][*pos + 3] = symbol;
}

void write_4(char **map, char symbol, int *pos)
{
    map[0][*pos + 2] = symbol;
    map[1][*pos + 1] = symbol;
    map[2][*pos] = symbol;
    map[3][*pos] = symbol;
    map[3][*pos + 1] = symbol;
    map[3][*pos + 2] = symbol;
    map[3][*pos + 3] = symbol;
    map[3][*pos + 4] = symbol;
    map[0][*pos + 3] = symbol;
    map[1][*pos + 3] = symbol;
    map[2][*pos + 3] = symbol;
    map[3][*pos + 3] = symbol;
    map[4][*pos + 3] = symbol;
}
