/*
** EPITECH PROJECT, 2018
** my_str_eg.c
** File description:
** str is egal
*/

#include "architect.h"

int my_str_eg(char *str1, char *str2)
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i])
            return (0);
        i++;
    }
    if (str1[i] != '\0' || str2[i] != '\0')
        return (0);
    return (1);
}
