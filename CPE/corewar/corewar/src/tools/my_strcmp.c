/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** my_strcmp
*/

#include "corewar.h"

int my_strcmp(char const *str1, char const *str2)
{
        int i = 0;

    if (!str1 && !str2)
        return (0);
    for ( ; str1[i] && str2[i] ; i++)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}
