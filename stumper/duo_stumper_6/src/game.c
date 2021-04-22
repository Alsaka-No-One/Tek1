/*
** EPITECH PROJECT, 2019
** game
** File description:
** something funny
*/

#include <stdio.h>
#include <stdlib.h>
#include "stumper.h"

static char **fill_2tab(char **arr, data_t *dat)
{
    int col = 1;

    arr[0][0] = '+';
    for (int com = 1; com != dat->size + 1; com++)
        arr[0][com] = '-';
    arr[0][dat->size + 1] = '+';
    arr[0][dat->size + 2] = '\0';
    arr[dat->size + 1][0] = '+';
    for (int cool = 1; cool != dat->size + 1; cool++)
        arr[cool][0] = '|';
    for (int cont = 1; cont != dat->size + 1; cont++) {
        for (col = 1; col != dat->size + 1; col++)
            arr[cont][col] = ' ';
        arr[cont][col] = '|';
        arr[cont][col + 1] = '\0';
    }
    for (int cor = 1; cor != dat->size + 1; cor++)
        arr[dat->size + 1][cor] = '-';
    arr[dat->size + 1][dat->size + 1] = '+';
    arr[dat->size + 1][dat->size + 2] = '\0';
    return (arr);
}

static char *get_place(data_t *dat, char *save, char *str)
{
    int co = 0;
    int ui = 0;

    for (ui = 0; str[ui] != ',' && str[ui] != '\0'; ui++);
    if (str[ui] != '\0')
        ui++;
    else
        dat->pasta = 2;
    for (; str[ui] != '\0'; co++, ui++)
        save[co] = str[ui];
    save[co] = '\0';
    return (save);
}

static char **place(data_t *dat, char **arr, char *str, int pos)
{
    char *save = malloc(sizeof(str));
    int col = 0;
    int row = 0;

    if (save == NULL)
        return (NULL);
    col = atoi(str);
    save = get_place(dat, save, str);
    if (dat->pasta != 2) {
        row = atoi(save);
        verifs(dat, arr, col, row);
        if (pos == 1 && dat->pasta != 2)
            arr[row + 1][col + 1] = dat->player_one_symb;
        if (pos == 2 && dat->pasta != 2)
            arr[row + 1][col + 1] = dat->player_two_symb;
        free(save);
        return (arr);
    }
    free(save);
    return (arr);
}

static int game_loop(data_t *dat, char **arr)
{
    int stat = 0;
    char *str = NULL;
    size_t size = 0;
    int turn = 1;

    display(arr);
    while (stat == 0) {
        printf("Player %i> ", turn);
        if (getline(&str, &size, stdin) == -1)
            return (ERROR);
        arr = place(dat, arr, str, turn);
        if (dat->pasta != 2)
            display(arr);
        if (turn == 1 && dat->pasta != 2)
            turn = 2;
        else if (turn == 2 && dat->pasta != 2)
            turn = 1;
        dat->pasta = 1;
        return_victory(arr, dat, turn, &stat);
    }
    return (return_free(str));
}

int game(data_t *dat)
{
    char **arr = malloc(sizeof(char *) * (dat->size + 3));

    dat->pasta = 1;
    if (arr == NULL)
        return (ERROR);
    for (int ui = 0; ui != dat->size + 2; ui++) {
        arr[ui] = malloc(sizeof(char) * dat->size + 3);
        if (arr[ui] == NULL)
            return (ERROR);
    }
    arr = fill_2tab(arr, dat);
    arr[dat->size + 2] = NULL;
    if (game_loop(dat, arr) == ERROR)
        return (ERROR);
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
    return (SUCCESS);
}
