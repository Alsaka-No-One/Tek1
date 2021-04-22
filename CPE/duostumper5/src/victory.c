/*
** EPITECH PROJECT, 2019
** duostumper
** File description:
** check_victory
*/

#include <stdlib.h>
#include "stumper.h"

int victory(char **map, data_t *data)
{
    for (int i = 1; map[i + 1] != NULL; i++)
        if (victory_line(map[i], data) == SUCCESS)
            return (SUCCESS);
    for (int i = 1; map[0][i + 1] != '\0'; i++)
        if (victory_cols(map, i, data) == SUCCESS)
            return (SUCCESS);
    if (victory_diagonal(map, data) == SUCCESS)
        return (SUCCESS);
    if (victory_up_diagonal(map, data) == SUCCESS)
        return (SUCCESS);
    if (draw(map) == SUCCESS)
        return (SUCCESS);
    return (ERROR);
}
