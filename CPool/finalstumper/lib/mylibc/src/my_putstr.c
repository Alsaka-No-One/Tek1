/*
** EPITECH PROJECT, 2018
** Kaminari - MyLibC | My Put String
** File description:
** A function that displays the character of a string
*/

#include "mylibc.h"

void my_putstr(char *str)
{
    if (str == NULL)
        return;
    write (1, str, my_strlen(str));
}
