/*
** EPITECH PROJECT, 2019
** duostumper
** File description:
** imput
*/

#include "stumper.h"

int imput(int argc, char **argv)
{
    fight_t fight;

    if (argc != 3) {
        write(2, "Invalid number of arguments\n", 28);
        return (ERROR);
    }
    fight.pokemon1.name = "Pikachu";
    fight.pokemon1.attack = 80;
    fight.pokemon1.defense = 80;
    fight.pokemon1.speed = 90;
    fight.pokemon1.health = 80;
    fight.pokemon2.name = "Pidgoetto";
    fight.pokemon2.attack = 42;
    fight.pokemon2.defense = 42;
    fight.pokemon2.speed = 84;
    fight.pokemon2.health = 50;
    return (battle(&fight));
}
