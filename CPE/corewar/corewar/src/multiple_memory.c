/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** multiple_memory
*/

#include <stdlib.h>
#include "corewar.h"

int multiple_memory(champion_t *champion, char **argv)
{
    int tab[MAX_CHAMPION];
    int number_a = 0;

    (void)champion;
    for (int i = 0; argv[i] != NULL; i++) {
        if (my_strcmp(argv[i], "-a") == 1) {
            tab[number_a] = mgetnbr(argv[i + 1]);
            number_a += 1;
        }
    }
    tab[number_a] = -16;
    if (number_a > 1)
        if (check_nb(tab, number_a, "Overlap detected.\n") == ERROR)
            return (ERROR);
    return (SUCCESS);
}