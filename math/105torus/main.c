/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "torus.h"

torus_t fill_torus(char **av, torus_t tooorus)
{
    tooorus.a4 = atof(av[2]);
    tooorus.a3 = atof(av[3]);
    tooorus.a2 = atof(av[4]);
    tooorus.a1 = atof(av[5]);
    tooorus.a0 = atof(av[6]);
    tooorus.n = atoi(av[7]);
    return (tooorus);
}

int torus_main(char **av)
{
    torus_t argument = fill_torus(av, argument);

    if (atoi(av[1]) == 1)
        bisection_function(argument);
     else if (atoi(av[1]) == 2)
         newton(argument);
    else if (atoi(av[1]) == 3)
        secant(argument);
    else
        exit (84);
}

int test_nb(char *av)
{
    for (int u = 0; u != strlen(av); u++){
        if ((av[u] > '9' || av[u] < '0') && av[u] != '-')
            return (0);
    }
    return (1);
}

int pre_torus_main(char **av)
{
    for (int u = 3; u != 8; u++)
        if (test_nb(av[u]) == 0)
            exit (84);
    torus_main(av);
}

int main(int ac, char **av)
{
    if (ac != 8) {
        help_usage();
        return (84);
    } else
        pre_torus_main(av);
    return (0);
}
