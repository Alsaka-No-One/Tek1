/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** print a character
*/

#include <unistd.h>
#include "include/function.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
