/*
** EPITECH PROJECT, 2019
** fractal
** File description:
** Error handling
*/

#include <unistd.h>
#include "fractal.h"

int size_error(char **av)
{
    int a = my_strlen(av[2]);
    int b = my_strlen(av[3]);

    if (a != b) {
        write(2, "Invalid size of arguments\n", 26);
        return (84);
    }
}

int charact_error(char **av)
{
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (av[2][i] != '@' && av[2][i] != '.' && av[2][i] != '#') {
            write(2, "Invalid charact\n", 16);
            return (84);
        }
    }

    for (int i = 0; av[3][i] != '\0'; i++) {
        if (av[3][i] != '@' && av[3][i] != '.' && av[3][i] != '#') {
            write(2, "Invalid charact\n", 16);
            return (84);
        }
    }
    return (0);
}

int check_charact(char **av)
{
    for (int i = 0; av[2][i] != '\0' && av[3][i] != '\0'; i++) {
        if (av[2][i] == '@' && av[3][i] != '@') {
            write(2, "invalid place of charact\n", 25);
            return (84);
        }
    }

    for (int i = 0; av[2][i] != '\0' && av[3][i] != '\0'; i++) {
        if (av[3][i] == '@' && av[2][i] != '@') {
            write(2, "invalid place of charact\n", 25);
            return (84);
        }
    }
    return (0);
}

int check_middle_charact(char **av)
{
    int i = compteur_charact(av);
    int j = 0;

    for (int a = i + 1; av[2][a] != '\0'; a++, j++) {
       	if (av[2][a] == '@' && j - 1 != i) {
            write(2, "Wrong position of @\n", 20);
            return (0);
        }
    }
    return (0);
}

int check_error_return(char **av)
{
    if (size_error(av) == 84)
        return (84);
    if (charact_error(av) == 84)
        return (84);
    if (check_charact(av) == 84)
        return (84);
}
