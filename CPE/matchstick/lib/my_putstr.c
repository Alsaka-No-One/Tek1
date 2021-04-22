/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** Task02
*/

#include "include/function.h"

int my_putstr(char const *str)
{
    int compt = 0;

    while (str[compt] != '\0') {
        my_putchar (str[compt]);
        compt =  compt + 1;
    }
}
