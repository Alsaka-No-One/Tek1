/*
** EPITECH PROJECT, 2019
** st_to_ar
** File description:
** tuen a str to arr
*/

#include "stumper.h"

char **st_to_ar(char *str)
{
    char **save;
    int p = 0;
    int i = 0;
    int y = 0;
    int x = 0;

    for (; str[x] != '\n' && str[x] != '\0'; x++);
    for (int k = 0; str[k] != '\0'; k++)
        if (str[k] == '\n')
            y++;
    save = malloc(sizeof(char *) * ((y + 1) * (x + 1) + 1));
    for (int v = 0; v != y + 1; v++)
        save[v] = malloc(sizeof(char) * (x + 1));
    for (int c = 0; p != y + 1; c++, p++) {
        for (i = 0; str[c] != '\n' && str[c] != '\0'; i++, c++)
            save[p][i] = str[c];
    }
    return(save);
}
