/*
** EPITECH PROJECT, 2019
** duostumper
** File description:
** check_victory
*/

#include <stdio.h>
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
        return (2);
    return (ERROR);
}

void return_victory(char **arr, data_t *data, int turn, int *stat)
{
    int status = -1;

    status = victory(arr, data);
    if (status == SUCCESS) {
        if (turn == 2)
            printf("Player 1 won!\n");
        if (turn == 1)
            printf("Player 2 won!\n");
    }
    else if (status == 2)
        printf("Draw !\n");
    else
        return;
    *stat = 1;
    return;
}
