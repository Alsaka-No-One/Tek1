/*
** EPITECH PROJECT, 2019
** duostumper 2
** File description:
** write victory
*/

#include "my.h"

void write_victory(char **map, char *str)
{
    int i = 0;
    int j = 2;
    int linum = 1;

    while (str[i] != '\0') {
        if (j == 9) {
            j = 2;
            linum += 1;
        }
        if (map[linum][j] == str[i]) {
            map[linum][j] = str[i] - 32;
            i++;
        }
        j++;
    }
}
