/*
** EPITECH PROJECT, 2019
** fractal
** File description:
** The function (main)
*/

#include <unistd.h>
#include "fractal.h"

int start_fractal(char **av, int i)
{
    int j = 0;
    int result;

    while (av[2][j] != '@' && av[2][j] != '\0')
        j++;
    if (j == my_strlen(av[2]))
        return (84);
    result = j;
    for (int k = 1; k < i; k++)
        j *= result;
    return (draw_dractal(av, j));
}

int fractal(char **av)
{
    if (av[1][0] == '0') {
        write(1, "#\n", 2);
        return (0);
    }
    else
        return (start_fractal(av, my_getnbr(av[1])));
}
