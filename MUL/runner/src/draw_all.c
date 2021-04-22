/*
** EPITECH PROJECT, 2018
** MUL runner | draw_all
** File description:
** The function to draw_all
*/

#include "runner.h"

void reset_for_jb(game_t *game)
{
    game->jb->position.x += -10;
    if (game->jb->position.x == -10000) {
        game->jb->position.x = 3000;
        sfSprite_setPosition(game->jb->sprite, game->jb->position);
    }
}

void draw_all(sfRenderWindow *window, sprite_t *foreground, game_t *game)
{
    sfVector2f offset;

    offset.x = -10;
    sfSprite_setTexture(foreground->sprite, foreground->texture, sfTrue);
    sfSprite_setTexture(game->for2->sprite, game->for2->texture, sfTrue);
    infinite_management(foreground, game->for2, offset);
    sfSprite_move(foreground->sprite, offset);
    sfSprite_move(game->for2->sprite, offset);
    sfRenderWindow_drawSprite(window, foreground->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->for2->sprite, NULL);
    reset_for_jb(game);
}

void draw_trees(sfRenderWindow *window, game_t *game)
{
    sfVector2f offset;

    offset.x = -10;
    sfSprite_setTexture(game->jb->sprite, game->jb->texture, sfTrue);
    sfSprite_move(game->jb->sprite, offset);
    sfRenderWindow_drawSprite(window, game->jb->sprite, NULL);
    reset_for_jb(game);
}