/*
** EPITECH PROJECT, 2019
** duostumper
** File description:
** check_stumper
*/

#include "stumper.h"

int check_input(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9')
            && str[i] != ',')
            return (ERROR);
    }
    return (SUCCESS);
}
