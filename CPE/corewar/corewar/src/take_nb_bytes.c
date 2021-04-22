/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** take_nb_bytes
*/

#include "corewar.h"

int take_nb_bytes(int nb_bytes, char *map, int pos)
{
    char bytes[nb_bytes + 1];

    for (int i = 0; i != nb_bytes; i++, pos++)
        bytes[i] = map[pos];
    bytes[nb_bytes] = '\0';
    return (mgetnbr(bytes));
}