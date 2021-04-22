/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** bytes_to_int
*/

#include <unistd.h>

int bytes_to_int(char *map, int start, int size)
{
    int nb = 0;

    for (int i = 0 ; i < size ; i++) {
        nb += map[start + i];
        if (i + 1 < size)
            nb *= 10;
    }
    return (nb);
}