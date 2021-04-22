/*
** EPITECH PROJECT, 2019
** CPE matchstick | remove condition
** File description:
** The function that check the remove
*/

#include "function.h"
#include "stick.h"

int check_buffer(char *buf)
{
    int i = 0;

    while (buf[i] != '\0') {
        if ((buf[i] < '0' || buf[i] > '9') && buf[i] != '\n')
            return (1);
        i++;
    }
    return (0);
}

int remove_condition(int max, coord_t *coord, char **map, int height)
{
    if ((coord->stick = print_number_remove()) == 84)
        return (-1);
    if (coord->stick <= 0) {
        my_putstr("Error: you have to remove at least one match\n");
        my_putstr("Line: ");
        my_put_nbr(coord->line);
        my_putchar('\n');
        if ((coord->line = check_buff(height, max)) == -1)
            return (-1);
        coord->stick = remove_condition(max, coord, map, height);
    } else if (coord->stick > max) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(max);
        my_putstr(" matches per turn\n");
        my_putstr("Line: ");
        my_put_nbr(coord->line);
        my_putchar('\n');
        if ((coord->line = check_buff(height, max)) == -1)
            return (-1);
        coord->stick = remove_condition(max, coord, map, height);
    }
    coord->stick = check_stick_left(coord, max, map, height);
    return (coord->stick);
}