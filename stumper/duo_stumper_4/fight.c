/*
** EPITECH PROJECT, 2019
** fight
** File description:
** handle the fight
*/

#include "stumper.h"

int verif_win(fight_t *fig)
{
    if (fig->pokemon1.health == 0) {
        printf("%s is KO\n", fig->pokemon1.name);
        printf("%s wins the fight!\n", fig->pokemon2.name);
        return (1);
    }
    if (fig->pokemon2.health == 0) {
        printf("%s is KO\n", fig->pokemon2.name);
        printf("%s wins the fight!\n", fig->pokemon1.name);
        return (1);
    }
    return (0);
}

int turn1(fight_t *fig, int call)
{
    int dmg = 0;
    int dmg_2 = 0;

    dmg = rand() % fig->pokemon1.attack;
    dmg_2 = dmg - fig->pokemon2.defense;
    if (dmg_2 < 0)
        dmg_2 = 0;
    fig->pokemon2.health -= dmg_2;
    if (fig->pokemon2.health < 0)
        fig->pokemon2.health = 0;
    printf("%s attacks for %i damage\n", fig->pokemon1.name, dmg);
    printf("%s blocks %i damage\n", fig->pokemon2.name, fig->pokemon2.defense);
    printf("%s loses %i health", fig->pokemon2.name, dmg_2);
    printf(" (%i left)\n", fig->pokemon2.health);
    if (verif_win(fig) == 1)
        return (1);
    if (call == 1)
        if (turn2(fig, 0) == 1)
            return (1);
    return (0);
}

int call_turn(fight_t *fig)
{
    if (fig->pokemon1.speed > fig->pokemon2.speed) {
        if (turn1(fig, 1) == 1)
            return (1);
    }
    else
        if (turn2(fig, 1) == 1)
            return (1);
}

int battle(fight_t *fig)
{
    for (int com = 0; fig->list[com].name != NULL; com++) {
        printf("Pokemon %s has %i", fig->list[com].name, fig->list[com].attack);
        printf(", %i defense, ", fig->list[com].defense);
        printf("%i speed and %i", fig->list[com].speed, fig->list[com].health);
        printf("%s\n", "health");
    }
    srand(time(NULL));
    while (1) {
        if (call_turn(fig) == 1)
            return (1);
    }
}
