/*
** EPITECH PROJECT, 2019
** CPE matchstick | create map
** File description:
** The function to create the map
*/

#include "stick.h"
#include "function.h"

char **create_map(int height)
{
    char **map = NULL;

    if ((map = malloc(sizeof(char *) * (height + 4))) == NULL)
        return (NULL);
    for (int i = 0; i <= height + 2; i++) {
        if ((map[i] = malloc(sizeof(char) * (height * 3 + 1))) == NULL)
            return (NULL);
    }
    return (map);
}

char **have_the_sticks(int height, char **map)
{
    int left_recov = 1;
    int j = left_recov;
    int right_recov = height * 2 - 1;

    while (height != 1) {
        if (j == right_recov) {
            map[height][j] = '|';
            right_recov -= 1;
            left_recov += 1;
            j = left_recov;
            height -= 1;
        }
        map[height][j] = '|';
        j++;
    }
    return (map);
}

char **have_last_line(int height, char **map)
{
    int i = 1;
    int j = 1;
    
    while (i < height + 1) {
        if (j == height * 2) {
            map[i][j] = '*';
            j = 1;
            i++;
        }
        if (i != height + 1)
            map[i][j] = ' ';
        j++;
    }
    have_the_sticks(height, map);
    return (map);
}

char **fill_the_map(int height)
{
    char **map = NULL;

    if ((map = create_map(height)) == NULL)
        return (NULL);
    for (int i = 0; i < height + 2; i++)
        map[i][0] = '*';
    for (int i = 0; i <= height * 2; i++) {
        map[0][i] = '*';
        map[height + 1][i] = '*';
    }
    map = have_last_line(height, map);
    return (map);
}