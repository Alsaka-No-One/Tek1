/*
** EPITECH PROJECT, 2019
** duostumper
** File description:
** draw
*/

#include <stdlib.h>
#include "stumper.h"

static int loop_draw(char **map, int j)
{
    for (int i = 1; map[j][i + 1] != '\0'; i++)
        if (map[j][i] == ' ')
            return (ERROR);
    return (SUCCESS);
}

int draw(char **map)
{
    int status = 0;

    for (int j = 1; map[j + 1] != NULL; j++)
        if (loop_draw(map, j) == ERROR)
            return (ERROR);
    return (SUCCESS);
}
