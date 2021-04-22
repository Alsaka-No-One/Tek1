/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** line_correct
*/

#include "tetris.h"
#include "data.h"

static void delete_line(char **map, int i)
{
    for (int j = 1; map[i][j + 1] != '\0'; j++)
        map[i][j] = ' ';
    for (; i != 1; i--) {
        for (int j = 1; map[i][j + 1] != '\0'; j++) {
            map[i][j] = map[i - 1][j];
            map[i - 1][j] = ' ';
        }
    }
}

void line_correct(char **map, data_t *data)
{
    int line = 0;

    (void)data;
    for (int i = 1; map[i + 1] != NULL; i++) {
        for (int j = 1; map[i][j + 1] != '\0'; j++)
            (map[i][j] == ' ') ? line = -1 : 0;
        if (line != -1)
            delete_line(map, i);
        line = 0;
    }
}