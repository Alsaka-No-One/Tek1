/*
** EPITECH PROJECT, 2018
** Kaminari - MyLibC | My Put Character
** File description:
** A function that displays one character
*/

#include "mylibc.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
