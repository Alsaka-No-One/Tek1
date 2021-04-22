/*
** EPITECH PROJECT, 2019
** duostumper
** File description:
** victory
*/

#include <stdlib.h>
#include "stumper.h"

int victory_line(char *map, data_t *data)
{
    int player_one = 0;
    int player_two = 0;

    for (int i = 1; map[i + 1] != '\0'; i++) {
        if (map[i] == data->player_one_symb)
            player_one += 1;
        if (map[i] == data->player_two_symb)
            player_two += 1;
    }
    if (player_one == data->size
        || player_two == data->size)
        return (SUCCESS);
    return (ERROR);
}

int victory_cols(char **map, int i, data_t *data)
{
    int player_one = 0;
    int player_two = 0;

    for (int j = 1; map[j + 1] != NULL; j++) {
        if (map[j][i] == data->player_one_symb)
            player_one += 1;
        if (map[j][i] == data->player_two_symb)
            player_two += 1;
    }
    if (player_one == data->size
        || player_two == data->size)
        return (SUCCESS);
    return (ERROR);
}

int victory_diagonal(char **map, data_t *data)
{
    int x = 1;
    int y = 1;
    int player_one = 0;
    int player_two = 0;

    for (; x <= data->size; x++, y++) {
        if (map[x][y] == data->player_one_symb)
            player_one += 1;
        if (map[x][y] == data->player_two_symb)
            player_two += 1;
    }
    if (player_one == data->size
        || player_two == data->size)
        return (SUCCESS);
    return (ERROR);
}

int victory_up_diagonal(char **map, data_t *data)
{
    int x = data->size;
    int y = 1;
    int player_one = 0;
    int player_two = 0;

    for (; y <= data->size; x--, y++) {
        if (map[x][y] == data->player_one_symb)
            player_one += 1;
        if (map[x][y] == data->player_two_symb)
            player_two += 1;
    }
    if (player_one == data->size
        || player_two == data->size)
        return (SUCCESS);
    return (ERROR);
}
