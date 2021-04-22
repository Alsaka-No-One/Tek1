/*
** EPITECH PROJECT, 2019
** CPE matchstick | new map
** File description:
** The function that draw the map which has been changed
*/

#include "function.h"
#include "stick.h"

int check_stick_left(coord_t* coord, int max, char **map, int height)
{
    int count_left = 0;

    for (int i = 1; map[coord->line][i] != '*'; i++)
        if (map[coord->line][i] == '|')
            count_left++;
    if (count_left < coord->stick) {
        my_putstr("Error: not enough matches on this line\n");
        my_putstr("Line: ");
        my_put_nbr(coord->line);
        my_putchar('\n');
        coord->line = check_buff(height, max);
        coord->stick = remove_condition(max, coord, map, height);
    }
    return (coord->stick);
}

void display_human_move(int line, int stick)
{
    my_putstr("Player removed ");
    my_put_nbr(stick);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

void display_player_map(int height, int line, int stick, char **map)
{
    int i = height * 2 - 1;
    int count = 0;

    display_human_move(line, stick);
    while (count != stick) {
        if (map[line][i] == ' ')
            i--;
        else {
            map[line][i] = ' ';
            i--;
            count++;
        }
    }
    print_map(height, map);
}