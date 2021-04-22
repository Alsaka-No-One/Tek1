/*
** EPITECH PROJECT, 2019
** check error
** File description:
** The function to check error
*/

#include "stumper.h"

int error(char *argv)
{
    for (int i = 0; argv[i] != '\0'; i++) {
        if (argv[i] < 'A' || argv[i] > 'Z' || argv[i] < 'a' || argv[i] > 'z'
            || argv[i] != ' ' || argv[i] != '\t')
            return (84);
        else
            return (0);
    }
}
