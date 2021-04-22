/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** life_rect
*/

#include "my_defender.h"

void life_rect(game_t *game, int i)
{
    game->ig.charact[i].rc_life.x = 50.0;
    game->ig.charact[i].rc_life.y = 5.0;
    game->ig.charact[i].sh_life = init_button_life(game->ig.charact[i].sh_life,
            create_vector(0.0, 0.0),
            game->ig.charact[i].rc_life);
}

void position_life(game_t *game, int i)
{
    sfVector2f pos = sfSprite_getPosition(game->ig.charact[i].minion.sprite);

    pos.x += 15.0;
    pos.y -= 2.0;
    sfRectangleShape_setPosition(game->ig.charact[i].sh_life, pos);
    sfRenderWindow_drawRectangleShape(game->window,
            game->ig.charact[i].sh_life, NULL);
}

void size_life(game_t *game, int j)
{
    game->ig.charact[j].rc_life.x = game->ig.charact[j].life * 5;
    sfRectangleShape_setSize(game->ig.charact[j].sh_life,
            game->ig.charact[j].rc_life);
    sfRenderWindow_drawRectangleShape(game->window,
            game->ig.charact[j].sh_life, NULL);
}