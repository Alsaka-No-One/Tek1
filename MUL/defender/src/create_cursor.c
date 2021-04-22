/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create_cursor
*/

#include "my_defender.h"

cursor_t create_cursor(sfRenderWindow *window)
{
    cursor_t cursor;

    initialize_draw_sprite(&cursor.view, window,
            "resources/cursor/cursor.png");
    initialize_draw_sprite(&cursor.d_and_d, window,
            "resources/game/tower4lvl1.png");
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    cursor.view.position = calcul_position_cursor(window);
    cursor.status = 0;
    return (cursor);
}

sfVector2f calcul_position_cursor(sfRenderWindow *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos_cursor = {0, 0};

    pos_cursor.x = pos.x;
    pos_cursor.y = pos.y;
    return (pos_cursor);
}

void display_cursor(game_t *game)
{
    game->cursor.view.position = calcul_position_cursor(game->window);
    if (game->cursor.status != 0) {
        game->cursor.d_and_d.position = game->cursor.view.position;
        game->cursor.d_and_d.position.x -= 50;
        game->cursor.d_and_d.position.y -= 100;
        sfSprite_setPosition(game->cursor.d_and_d.sprite,
                game->cursor.d_and_d.position);
        sfRenderWindow_drawSprite(game->window,
                game->cursor.d_and_d.sprite, NULL);
    }
    sfSprite_setPosition(game->cursor.view.sprite, game->cursor.view.position);
    sfRenderWindow_drawSprite(game->window, game->cursor.view.sprite, NULL);
}