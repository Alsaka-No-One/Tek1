/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** create_map
*/

#include <stdlib.h>
#include "tetris.h"
#include "data.h"

static void fill_border_map(char **map, data_t *data)
{
    for (int i = 0; i != data->map_row; i++) {
        map[i][0] = '|';
        map[i][data->map_col * 2 - 1] = '|';
    }
    for (int i = 0; i != data->map_col * 2; i++) {
        map[0][i] = '-';
        map[data->map_row - 1][i] = '-';
    }
    map[0][0] = '/';
    map[data->map_row - 1][0] = '\\';
    map[data->map_row - 1][data->map_col * 2 - 1] = '/';
    map[0][data->map_col * 2 - 1] = '\\';
}

static char *fill_spaces(char *str, int stop)
{
    int i = 0;

    for (; i != stop; i++)
        str[i] = ' ';
    str[i] = '\0';
    return (str);
}

char **create_map(data_t *data)
{
    char **map = malloc(sizeof(char *) * (data->map_row + 1));

    if (map == NULL)
        return (NULL);
    map[data->map_row] = NULL;
    for (int i = 0; i != data->map_row; i++) {
        map[i] = malloc(sizeof(char) * ((data->map_col * 2) + 1));
        if (map[i] == NULL)
            return (NULL);
        map[i] = fill_spaces(map[i], data->map_col * 2);
    }
    fill_border_map(map, data);
    return (map);
}