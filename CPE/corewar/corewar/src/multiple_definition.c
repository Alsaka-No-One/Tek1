/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** multiple_definition
*/

#include <stdlib.h>
#include "corewar.h"

int check_nb(int *tab, int nb, char *commit)
{
    int turn = 0;
    int check = tab[turn];
    int time = 0;

    for (int i = 0; turn != nb; i++) {
        if (tab[i] == -16) {
            i = 0;
            turn += 1;
            check = tab[turn];
            time = 0;
        }
        if (check == tab[i])
            time += 1;
        if (time == 2) {
            my_put(commit, 2);
            return (ERROR);
        }
    }
    return (SUCCESS);
}
static int change_nb(int *tab, int check)
{
    for (int i = 0; tab[i] != -16; i++) {
        if (check == tab[i]) {
            check += 1;
            i = 0;
        }
    }
    return (check);
}

static void last_check(champion_t *champion, int *tab)
{
    static int check = 1;

    check = change_nb(tab, check);
    for (int i = 0; tab[i] != -16; i++) {
        if (champion->nb_player == tab[i]
            && champion->verif.is_number != 1) {
            champion->nb_player = check;
            check += 1;
            return;
        }
        if (champion->verif.is_number != 1) {
            champion->nb_player = check;
            check += 1;
            return;
        }
        if (check == champion->nb_player && champion->verif.is_number != 1)
            check += 1;
    }
}

static int multiple_number(champion_t *champion, char **argv)
{
    int tab[MAX_CHAMPION];
    int number_n = 0;

    for (int i = 0; argv[i] != NULL; i++) {
        if (my_strcmp(argv[i], "-n") == 1) {
            tab[number_n] = mgetnbr(argv[i + 1]);
            number_n += 1;
        }
    }
    tab[number_n] = -16;
    if (number_n > 1)
        if (check_nb(tab, number_n,
            "double definition of prog number\n") == ERROR)
            return (ERROR);
    for (int i = 0; i != MAX_CHAMPION; i++)
        last_check(&champion[i], tab);
    return (SUCCESS);
}

int multiple_definition(champion_t *champion, char **argv)
{
    if (multiple_number(champion, argv) == ERROR)
        return (ERROR);
    if (multiple_memory(champion, argv) == ERROR)
        return (ERROR);
    return (SUCCESS);
}