/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** free_array
*/

#include "lemin.h"
#include "struct.h"

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}