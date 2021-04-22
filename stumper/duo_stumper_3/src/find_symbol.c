/*
** EPITECH PROJECT, 2019
** norm
** File description:
** help to not come next week
*/

#include "stumper.h"

static void display_show(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        printf("%s\n", map[i]);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}

static char symbol(int nbr, char **av, int pos_string)
{
    char symbol;
    int pos;

    pos = nbr % strlen(av[pos_string]);
    symbol = av[pos_string][pos];
    return (symbol);
}

int find_symbol(int pos_string, char **av, int pos_nbrs, char **show)
{
    char symb;
    int i = 0;

    while (av[pos_nbrs][i] != '\0') {
        if (pos_string == 0)
            fill_show(av, pos_nbrs, show, '0');
        else {
            symb = symbol(atoi(av[pos_nbrs]), av, pos_string);
            fill_show(av, pos_nbrs, show, symb);
        }
        i++;
    }
    display_show(show);
    return (0);
}
