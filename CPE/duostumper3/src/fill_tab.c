/*
** EPITECH PROJECT, 2019
** stumper 3
** File description:
** fill_tab
*/

#include "stumper.h"

void fill_tab(char ***map, int height)
{
    int i = 0;

    for (int j = 0; i < 5; j++) {
        if (i == 4 && j == height) {
            (*map)[i][j] = '\0';
            break;
        }
        if (j == height) {
            (*map)[i][j] = '\0';
            i += 1;
            j = 0;
        }
        (*map)[i][j] = ' ';
    }
    (*map)[5] = NULL;
}
