/*
** EPITECH PROJECT, 2018
** CPE pushswap | error_argument
** File description:
** The function to check if the arguments are good or not
*/

#include "../include/pushswap.h"

int error_loop(int i, char **argv)
{
    int ii = 0;

    while (argv[i][ii] != '\0') {
        if ((argv[i][ii] != '-' && argv[i][ii] < '0') || argv[i][ii] > '9')
            return (84);
        ii++;
    }
}

int error_argument(int argc, char **argv)
{
    for (int i = 1; i != argc; i++) {
        if (error_loop(i, argv) == 84)
            return (84);
    }
    return (0);
}