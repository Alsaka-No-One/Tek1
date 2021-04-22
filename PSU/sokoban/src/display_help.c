/*
** EPITECH PROJECT, 2018
** PSU my_sokoban | display_help
** File description:
** The function for the "-h"
*/

#include "../include/sokoban.h"

void display_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ");
    my_putstr("./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    ");
    my_putstr("map file representing the warehouse map, ");
    my_putstr("containing '#' for walls,\n");
    my_putstr("        ");
    my_putstr("'P' for the player, 'X' for boxes ");
    my_putstr("and 'O' for storage locations.");
}
