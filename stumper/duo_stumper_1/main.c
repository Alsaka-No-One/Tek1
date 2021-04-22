/*
** EPITECH PROJECT, 2019
** fractals
** File description:
** main
*/

#include <unistd.h>
#include "fractal.h"

int main(int ac, char **av)
{
    if (ac != 4) {
        write(2, "Invalid number of arguments\n", 28);
        return (84);
    } else if (check_error_return(av) == 84)
        return (84);
    else
        return (fractal(av));
}
