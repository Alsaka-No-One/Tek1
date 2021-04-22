/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** print a string
*/

#include "include/function.h"

int my_putstr(char const *str)
{
    int n = 0;

    while (str[n] != '\0'){
        my_putchar(str[n]);
        n = n + 1;
    }
    return (0);
}
