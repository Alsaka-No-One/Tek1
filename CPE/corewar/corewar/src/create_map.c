/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** create_map
*/

#include "stdlib.h"
#include "op.h"

void fill_map(char *map)
{
    for (size_t i = 0; i < MEM_SIZE; i++)
        map[i] = 0x00;
}

char *create_map(void)
{
    char *map = NULL;

    map = malloc(sizeof(char) * MEM_SIZE);
    if (map == NULL)
        return (NULL);
    fill_map(map);
    return (map);
}