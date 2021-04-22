/*
** EPITECH PROJECT, 2019
** CPE matchstick | help
** File description:
** The function for the -h
*/

#include "function.h"
#include "stick.h"

void display_usage(void)
{
    my_putstr("USAGE:\n");
    my_putstr("\t./matchstick nb1 nb2\n");
    my_putstr("\nDESCRIPTION:\n");
    my_putstr("\tnb1 --> The size of the map. It must be in [1 < nb1 < 100]");
    my_putstr("\n\tnb2 --> The number max of stick that you can remove\n");
}