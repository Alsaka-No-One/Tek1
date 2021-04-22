/*
** EPITECH PROJECT, 2019
** duostumper
** File description:
** fill_data
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stumper.h"

static int check_next(char **argv, int i, data_t *data)
{
    if (strcmp(argv[i], "-p1") == 0) {
        if (strlen(argv[i + 1]) != 1)
            return (ERROR);
        data->player_one_symb = argv[i + 1][0];
    }
    if (strcmp(argv[i], "-p2") == 0) {
        if (strlen(argv[i + 1]) != 1)
            return (ERROR);
        data->player_two_symb = argv[i + 1][0];
    }
    if (strcmp(argv[i], "-s") == 0) {
        if (atoi(argv[i + 1]) < 2)
            return (ERROR);
        data->size = atoi(argv[i + 1]);
    }
    return (SUCCESS);
}

int fill_data(int argc, char **argv)
{
    data_t data;
    int status = 0;

    data.player_one_symb = 'X';
    data.player_two_symb = 'O';
    data.size = 3;
    if (argc == 1)
        return (game(&data));
    for (int i = 0; argv[i] != NULL; i++) {
        if (argv[i][0] == '-')
            status = check_next(argv, i, &data);
        if (status == ERROR)
            return (ERROR);
    }
    if (data.player_one_symb == data.player_two_symb) {
        fprintf(stderr, "The two players can't have the same symbol!\n");
        fprintf(stderr, "Default: player 1 = X, player 2 = O\n");
        return (ERROR);
    }
    return (game(&data));
}
