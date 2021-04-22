/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** display_menu_pause
*/

#include "my_defender.h"

void display_menu_pause_two(game_t *game)
{
    set_color_text(game->pause.back,
            sfRectangleShape_getGlobalBounds(game->pause.button.back),
            sfRectangleShape_getPosition(game->pause.button.back),
            sfMouse_getPositionRenderWindow(game->window));
    sfRenderWindow_drawRectangleShape(game->window,
            game->pause.button.back, NULL);
    sfRenderWindow_drawText(game->window, game->pause.back, NULL);
    set_color_text(game->pause.quit,
            sfRectangleShape_getGlobalBounds(game->pause.button.quit),
            sfRectangleShape_getPosition(game->pause.button.quit),
            sfMouse_getPositionRenderWindow(game->window));
    sfRenderWindow_drawRectangleShape(game->window,
            game->pause.button.quit, NULL);
    sfRenderWindow_drawText(game->window, game->pause.quit, NULL);
    display_cursor(game);
    sfRenderWindow_display(game->window);
}

void display_menu_pause(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->pause.bg.sprite, NULL);
    set_color_text(game->pause.resume,
            sfRectangleShape_getGlobalBounds(game->pause.button.resume),
            sfRectangleShape_getPosition(game->pause.button.resume),
            sfMouse_getPositionRenderWindow(game->window));
    sfRenderWindow_drawRectangleShape(game->window,
            game->pause.button.resume, NULL);
    sfRenderWindow_drawText(game->window, game->pause.resume, NULL);
    display_menu_pause_two(game);
}
