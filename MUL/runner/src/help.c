/*
** EPITECH PROJECT, 2019
** MUL my_runner | help
** File description:
** The usage display
*/

#include "runner.h"

void display_usage() 
{
    my_putstr("USAGE:\n\t./my_runner [file]\n\n");
    my_putstr("DESCRIPTION:\n\tMy_runner is a project game. You are playing ");
    my_putstr("a running character\n\tand you have to dodge the obstacles ");
    my_putstr("and finish the map!\n\n");
    my_putstr("FILE:\n\tFill your file with SPACES or 1\n\t");
    my_putstr("\t1 means that you put a block\n\t\t");
    my_putstr("You can do whatever you want in this rectangle: width = 100");
    my_putstr(" height = 4\n\t");
    my_putstr("(The jump is bugging: if you put not enough block");
    my_putstr(" the jump will be too fast\n\t");
    my_putstr("and if you put too much block the jump will be really slow)\n");
    my_putstr("\tPut 6 blocks in order to have a 'normal' jump\n");
}