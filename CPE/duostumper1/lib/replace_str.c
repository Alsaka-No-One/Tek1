/*
** EPITECH PROJECT, 2019
** fractal
** File description:
** replace_str
*/

#include "include/function.h"

char *replace_str(char *str, char old, char new)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == old)
            str[i] = new;
    return (str);
}

    
