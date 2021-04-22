/*
** EPITECH PROJECT, 2019
** CPE matchstick | ai-2
** File description:
** The second part of the ai
*/

#include "function.h"
#include "stick.h"

int count_modulo(int line, char **map, int count, int max)
{
    if (count % max + 1 == 0) {
        line--;
        count = count_line_ai(line, map, max);
    }
    return (0);
}

int ai_stick_left(char **map, int line, int height)
{
    int i = 0;
    int count = 0;

    while (i != height * 2 - 1) {
        if (map[line][i] == '|')
            count++;
        i++;
    }
    if (count == 0)
        return (0);
    else
        return (1);
}

int replace_for_moment(int line, char **map, int height)
{
    if (ai_stick_left(map, line, height) == 0) {
        line--;
        line = replace_for_moment(line, map, height);
    } else {
        display_ai_map(height, line, 1, map);
        print_map(height, map);
    }
    if (count_for_ai(height, map) == 0)
        return (1);
    return (line);
}