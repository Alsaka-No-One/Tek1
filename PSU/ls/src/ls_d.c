/*
** EPITECH PROJECT, 2019
** PSU my_ls | option
** File description:
** The function for the -d
*/

#include "ls.h"

void ls_d(int argc, char **argv)
{
    int i = 1;

    if (argc == 2) {
        my_printf("\033[36m\033[1m.\033[0m");
        return;
    }
    while (i <= argc - 1) {
        if (argv[i][0] != '-')
            my_printf("%s   ", argv[i]);
        i++;
    }
    exit(0);
}