/*
** EPITECH PROJECT, 2019
** CPE matchstick | AI
** File description:
** The functions for the AI
*/

#include "function.h"
#include "stick.h"

int count_line_ai(int line, char **map, int max)
{
    int i = 1;
    int count = 0;

    while (map[line][i] != '*') {
        if (map[line][i] == '|')
            count += 1;
        i++;
    }
    if (count == 0) {
        if (line != 0) {
            line --;
            count = count_line_ai(line, map, max);
            return (count);
        }
        else
            return (0);
    }
    else
        return (count);
}

int nb_stick_remove(int line, int max, char **map)
{
    int nb = 1;
    int stick_left = 0;

    stick_left = count_line_ai(line, map, max);
    (void)nb;
    (void)stick_left;
    return (line);
}

int count_for_ai(int height, char **map)
{
    int count = 0;
    int i = 1;
    int j = 1;

    while (i <= height + 1) {
        if (map[i][j] == '|')
            count += 1;
        if (j == height * 2) {
            j = 0;
            i++;
        }
        j++;
    }
    return (count);
}

void display_ai_map(int height, int line, int stick, char **map)
{
    int i = height * 2 - 1;
    int count = 0;

    my_putstr("AI's turn...\n");
    my_putstr("AI removed ");
    my_put_nbr(stick);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
    while (count != stick) {
        if (map[line][i] == ' ') {
            map[line][i] = ' ';
            i--;
        }
        else {
            map[line][i] = ' ';
            i--;
            count++;
        }
    }
}

int ai(int height, char **map, int max)
{
    (void)max;
    if (replace_for_moment(height, map, height) == 1)
        return (1);
    return (0);
}
