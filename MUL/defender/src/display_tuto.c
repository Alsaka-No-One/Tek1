/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** display_tuto
*/

#include "my_defender.h"

static void destroy(sfTexture *texture, sfSprite *sprite)
{
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

int display_tuto(game_t *game)
{
    sfTexture *texture;
    sfSprite *sprite;
    int status = 1;

    texture = sfTexture_createFromFile("resources/menu/tuto.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, create_vector(700.0, 200.0));
    while (sfRenderWindow_isOpen(game->window) && status == 1) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window,
                game->menu.background.sprite, NULL);
        sfRenderWindow_drawSprite(game->window, sprite, NULL);
        display_cursor(game);
        sfRenderWindow_display(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
            status = 0;
    }
    destroy(texture, sprite);
    return (0);
}