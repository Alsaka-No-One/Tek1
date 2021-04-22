/*
** EPITECH PROJECT, 2018
** BSQ | error
** File description:
** A function that display error
*/

#include "../include/bsq.h"

void error_output(char *str)
{
    write(2, str, my_strlen(str));
}

void error_open(void)
{
    my_printf("Failure open\n");
}
