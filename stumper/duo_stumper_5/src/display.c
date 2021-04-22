/*
** EPITECH PROJECT, 2019
** duostumper
** File description:
** display
*/

#include <stdio.h>
#include "stumper.h"

void display(char **map)
{
    if (!map)
        return;
    for (int i = 0; map[i] != NULL; i++)
        printf("%s\n", map[i]);
}
