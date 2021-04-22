/*
** EPITECH PROJECT, 2018
** CPE BSQ | string_to_tab
** File description:
** A function that transform a string into a tab
*/

#include "../include/bsq.h"

int find_nb_cols(char *src)
{
    int i = 0;

    while (src[i] != '\n')
        i++;
    return (i);
}

char **string_to_tab(char *src, int nb_linum, int nb_cols, char **dest)
{
    int linum = 0;
    int cols = 0;
    int count = 0;

    dest = malloc(sizeof(char *) * (nb_linum * (nb_cols + 1)));
    for (int j = 0; j < nb_linum + 1; j++) {
        dest[j] = malloc(sizeof(char) * (nb_cols + 2));
        dest[j][nb_cols] = '\0';
    }
    while (src[count] != '\0') {
        if (src[count] == '\n') {
            cols = 0;
            linum ++;
            count++;
        }
        dest[linum][cols] = src[count];
        cols++;
        count++;
    }
    return (dest);
}

void print_tab(char **tab, int nb_linum, int nb_cols)
{
    int linum = 0;

    while (linum < nb_linum) {
        write(1, tab[linum], nb_cols);
        my_putchar('\n');
        linum++;
    }
}
