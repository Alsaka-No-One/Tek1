/*
** EPITECH PROJECT, 2018
** MUL my_hunter | moove bird
** File description:
** The function to moove bird
*/

#include "../include/my_hunter.h"

void moove_bird(sprite_t *duck, sfVector2f offset, int nb)
{
    srand(time(NULL));
    offset.x = nb;
    offset.y = 0;
    sfSprite_move(duck->sprite, offset);
}

int manage_speed(void)
{
    int nb;

    srand(time(NULL));
    nb = (rand() % (20 - 5 + 1)) + 5;
    return (nb);
}
