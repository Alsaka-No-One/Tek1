/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** my_str_cpy
*/

#include <stdlib.h>
#include "corewar.h"

char *my_strcpy(char *str)
{
    char *cpy = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    if (cpy == NULL)
        return (NULL);
    while (str[i] != '\0') {
        cpy[i] = str[i];
        i++;
    }
    cpy[i] = '\0';
    return (cpy);
}
