/*
** EPITECH PROJECT, 2018
** MUL my_hunter | respawn bird
** File description:
** The function that make the bird respawn
*/

#include "../include/my_hunter.h"

sprite_t *respawn_bird(sprite_t *duck)
{
    duck->position.x = duck->position.x + duck->nb;
    if (duck->position.x >= 1950) {
        duck->lost_condition = duck->lost_condition - 1;
        duck->position.x = -200;
        srand(time(NULL));
        duck->position.y = (rand() % (700 - 100 + 1)) + 100;
        duck->nb = manage_speed();
        sfSprite_setPosition(duck->sprite, duck->position);
    }
    return (duck);
}

void *lost_check(sprite_t *duck, sfRenderWindow *window)
{
    if (duck->lost_condition == 0)
        sfRenderWindow_close(window);
}
