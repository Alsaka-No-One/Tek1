/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** fill_data
*/

#include <stddef.h>
#include "corewar.h"

void init_data(data_t *data)
{
    data->dump = 0;
    for (int i = 0; i <= MAX_CHAMPION; i++) {
        data->champion[i].filename = NULL;
        data->champion[i].nb_player = -1;
        data->champion[i].verif.alive = 1;
        data->champion[i].verif.is_number = -1;
        data->champion[i].verif.is_memory = -1;
    }
}

static void number(char **argv, int i, champion_t *champ, int *nb)
{
    int check = 0;

    check = mgetnbr(argv[i + 1]);
    if (check == *nb)
        *nb += 1;
    champ->nb_player = check;
    champ->verif.is_number = 1;
}

int fill_data(char **argv, int i, data_t *data)
{
    static int nb_champ = 0;
    static int nb = 1;

    if (i == 0)
        return (SUCCESS);
    if (argv[i][0] != '-' && argv[i - 1][0] != '-') {
        data->champion[nb_champ].filename = my_strcpy(argv[i]);
        if (data->champion[nb_champ].filename == NULL)
            return (ERROR);
        if (data->champion[nb_champ].nb_player == -1) {
            data->champion[nb_champ].nb_player = nb;
            nb += 1;
        }
        nb_champ += 1;
    }
    if (my_strcmp(argv[i], "-n") == 1)
        number(argv, i, &data->champion[nb_champ], &nb);
    memory_champ(argv, i, &data->champion[nb_champ]);
    return (SUCCESS);
}