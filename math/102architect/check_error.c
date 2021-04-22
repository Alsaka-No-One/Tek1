/*
** EPITECH PROJECT, 2018
** Maths 102architect | check_error
** File description:
** The function to check bad argument
*/

#include "include/architect.h"

void error_argument(int ac, char **av)
{
    int j = 0;
    int k = 0;

    for (int i = 1; i != ac; j++) {
        if (av[i][j] == '\0') {
            i++;
            j = 0;
        }
        printf("OK\n");
        //if ((av[i][j] > '0' || av[i][j] < '9') || av[i][j] != '-')
        //exit(84);
        if (my_str_eg(av[1], "-h") != 1 || my_str_eg(av[1], "-t")
            != 1 || my_str_eg(av[1], "-z") != 1 || my_str_eg(av[1], "-r")
            != 1 || my_str_eg(av[1], "-s") != 1)
            exit (84);
    }
}
