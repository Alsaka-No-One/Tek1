/*
** EPITECH PROJECT, 2018
** undefined
** File description:
** my_putchar
*/

#include "include/function.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}