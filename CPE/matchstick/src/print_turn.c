/*
** EPITECH PROJECT, 2019
** CPE matchstick | print turn
** File description:
** The function to print the turn
*/

#include "function.h"
#include "stick.h"

int print_human_turn(void)
{
    size_t n = 0;
    char *buf = NULL;
    int i = 0;

    my_putstr("Line: ");
    if (getline(&buf, &n, stdin) == -1)
        return (-5);
    if (check_buffer(buf) == 1) {
        my_putstr("Error: invalid input (positive number expected)\n");
        i = print_human_turn();
    }
    i = my_getnbr(buf);
    return (i);
}

int print_number_remove(void)
{
    size_t n = 0;
    char *buf = NULL;
    static int j = 0;

    my_putstr("Matches: ");
    if (getline(&buf, &n, stdin) == -1)
        return (84);
    if (check_buffer(buf) == 1) {
        my_putstr("Error: invalid input (positive number expected)\n");
        j = print_number_remove();
    }
    j = my_getnbr(buf);
    return (j);
}