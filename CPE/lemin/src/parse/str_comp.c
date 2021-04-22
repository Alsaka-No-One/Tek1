/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** str_comp
*/

#include "lemin.h"
#include "struct.h"

int my_strcomp(char const *str, char const *comp_str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != comp_str[i])
            return (-1);
    }
    return (1);
}
