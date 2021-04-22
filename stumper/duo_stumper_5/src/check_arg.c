/*
** EPITECH PROJECT, 2019
** duostumper
** File description:
** check_arg
*/

#include <stdio.h>
#include <string.h>
#include "stumper.h"

static int check_nb_arg(int argc)
{
    if (argc != 1 && argc != 3 && argc != 5
        && argc != 7) {
        fprintf(stderr, "Invalid number of argument!\n");
        return (ERROR);
    }
    return (SUCCESS);
}

static int check_symb(char **argv, int i)
{
    if (argv[i][0] == '-' && strlen(argv[i]) != 1)
        return (ERROR);
    return (SUCCESS);
}

int check_arg(int argc, char **argv)
{
    int status = 0;

    if (check_nb_arg(argc) == ERROR)
        return (ERROR);
    for (int i = 0; argv[i] != NULL; i++) {
        if (i != 1 && i != 3 && i != 5)
            status = check_symb(argv, i);
        if (status == ERROR)
            return (ERROR);
        if ((i == 1 || i == 3 || i == 5)
            && argv[i][0] != '-')
            return (ERROR);
        if (argv[i][0] == '-'
            && strcmp(argv[i], "-s") != 0
            && strcmp(argv[i], "-p1") != 0
            && strcmp(argv[i], "-p2") != 0
            && status != SUCCESS)
            return (ERROR);
    }
    return (fill_data(argc, argv));
}
