/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** error_gestion
*/

static const int MAX_INT = 2147483647;

#include <stdlib.h>
#include <stdio.h>
#include "op.h"
#include "corewar.h"

static int number_champion(int argc, char **argv, int i, int *is_champion)
{
    static int nbr_champion = 0;

    if (i != 0)
        if (argv[i][0] != '-' && argv[i - 1][0] != '-') {
            *is_champion = 0;
            nbr_champion += 1;
        }
    if (i == argc - 1 && (nbr_champion < 2 || nbr_champion > MAX_CHAMPION))
        return (ERROR);
    return (SUCCESS);
}

static int check_champion(int argc, char **argv, int i, int *is_champion)
{
    int check = 0;

    if (my_strcmp(argv[i], "-a")) {
        if (*is_champion != 1)
            *is_champion = 1;
        if (i != argc - 1)
            check = mgetnbr(argv[i + 1]);
        if (check >= 0 && check <= MAX_INT)
            return (SUCCESS);
    }
    if (number_champion(argc, argv, i, is_champion) == ERROR)
        return (ERROR);
    if (i == argc - 1 && *is_champion == 1)
        return (ERROR);
    if (argv[i][0] != '-')
        return (SUCCESS);
    return (ERROR);
}

static int argument(int argc, char **argv, int i, data_t *data)
{
    static int dump = 0;
    static int is_champion = 0;

    if (my_strcmp(argv[i], "-dump") == 1 && dump == 0) {
        if (i != argc - 1 && (mgetnbr(argv[i + 1]) >= 0)) {
            data->dump = mgetnbr(argv[i + 1]);
            return (SUCCESS);
        }
    }
    if (my_strcmp(argv[i], "-n") == 1)
        if (i != argc - 1
            && (mgetnbr(argv[i + 1]) >= 1
            && mgetnbr(argv[i + 1]) <= MAX_CHAMPION)) {
            is_champion = 1;
            return (SUCCESS);
        }
    if (check_champion(argc, argv, i, &is_champion) == SUCCESS)
        return (SUCCESS);
    return (ERROR);
}

int gestion_argument(int argc, char **argv)
{
    data_t data;

    init_data(&data);
    if (argc == 2 && my_strcmp(argv[1], "-h")) {
        display_help();
        return (SUCCESS);
    } else if (argc < 3) {
        display_help();
        return (ERROR);
    }
    for (int i = 0; i <= argc - 1; i++) {
        if (argument(argc, argv, i, &data) == ERROR)
            return (ERROR);
        if (fill_data(argv, i, &data) == ERROR)
            return (ERROR);
    }
    if (multiple_definition(data.champion, argv) == ERROR)
        return (ERROR);
    data.time_cycle_die = CYCLE_TO_DIE;
    data.last_name = NULL;
    return (vm(&data));
}