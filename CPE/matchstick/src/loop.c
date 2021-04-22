/*
** EPITECH PROJECT, 2019
** CPE matchstick | loop
** File description:
** The function to have the loop until the game end
*/

#include "function.h"
#include "stick.h"

int check_buff(int height, int max)
{
    int i = print_human_turn();

    if (i == -5)
        return (-1);
    if (i > height || i <= 0) {
        my_putstr("Error: this line is out of range\n");
        i = check_buff(height, max);
    }
    return (i);
}

int check_stick(char **map, int height)
{
    int j = 1;
    int i = 1;

    while (i != height + 1) {
        if (j == height * 2) {
            j = 1;
            i += 1;
        }
        if (map[i][j] == '|')
            return (1);
        j++;
    }
    return (0);
}

int game_loop(int height, int max, char **map)
{
    coord_t *coord = NULL;

    coord = malloc(sizeof(coord_t) * 2);
    print_map(height, map);
    while (check_stick(map, height) != 0) {
        my_putstr("Your turn:\n");
        if ((coord->line = check_buff(height, max)) == -1)
            return (3);
        if ((coord->stick = remove_condition(max, coord, map, height)) == -1)
            return (3);
        display_player_map(height, coord->line, coord->stick, map);
        if (count_for_ai(height, map) == 0)
            return (2);
        if (ai(height, map, max) == 1) {
            my_putstr("I lost... snif... but I'll get you next time!!\n");
            return (1);
        }
    }
    return (0);
}