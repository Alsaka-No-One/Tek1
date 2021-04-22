/*
** EPITECH PROJECT, 2019
** duo stumper 2
** File description:
** error_argument
*/

#include <unistd.h>
#include "my.h"

static int check_argument(char **av)
{
    if (av[1][0] != '-' || av[1][1] != 'g')
        return (ERROR);
    return (SUCCESS);
}

int error_argument(int argc, char **argv)
{
    if (argc <= 2 || argc > 7) {
        write(2, "Wrong number of arguments\n", 26);
        return (ERROR);
    }
    if (argc == 6 || argc == 4) {
        write(2, "Wrong number of arguments\n", 26);
        return (ERROR);
    }
    if (argc == 3 && check_argument(argv) != ERROR)
        return (boggle_3_argument(argv));
    else if (argc > 3)
        return (boggle(argc, argv));
    return (0);
}
