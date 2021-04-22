/*
** EPITECH PROJECT, 2019
** fight 2
** File description:
** the next fight
*/

#include "stumper.h"

int turn2(fight_t *fig, int call)
{
    int dmg = 0;
    int dmg_2 = 0;

    dmg = rand() % fig->pokemon2.attack;
    dmg_2 = dmg - fig->pokemon1.defense;
    if (dmg_2 < 0)
        dmg_2 = 0;
    fig->pokemon1.health -= dmg_2;
    if (fig->pokemon1.health < 0)
        fig->pokemon1.health = 0;
    printf("%s attacks for %i damage\n", fig->pokemon2.name, dmg);
    printf("%s blocks %i damage\n", fig->pokemon1.name, fig->pokemon1.defense);
    printf("%s loses %i health", fig->pokemon1.name, dmg_2);
    printf(" (%i left)\n", fig->pokemon1.health);
    if (verif_win(fig) == 1)
        return (1);
    if (call == 1)
        if (turn1(fig, 0) == 1)
            return (1);
    return (0);
}
