/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** tower_rect
*/

#include "my_defender.h"

void tower_rect(game_t *game)
{
    game->ig.tower->rect.tower1 = init_button(game->ig.tower->rect.tower1,
                                            create_vector(600.0, 900.0),
                                            create_vector(290.0, 145.0));
    game->ig.tower->rect.tower2 = init_button(game->ig.tower->rect.tower2,
                                            create_vector(927.0, 900.0),
                                            create_vector(290.0, 145.0));
    game->ig.tower->rect.tower3 = init_button(game->ig.tower->rect.tower3,
                                            create_vector(1260.0, 900.0),
                                            create_vector(290.0, 145.0));
    game->ig.tower->rect.tower4 = init_button(game->ig.tower->rect.tower4,
                                            create_vector(1590.0, 900.0),
                                            create_vector(290.0, 145.0));
}

void display_tower_rect(game_t *game)
{
    sfRenderWindow_drawRectangleShape(game->window,
            game->ig.tower->rect.tower1, NULL);
    sfRenderWindow_drawRectangleShape(game->window,
            game->ig.tower->rect.tower2, NULL);
    sfRenderWindow_drawRectangleShape(game->window,
            game->ig.tower->rect.tower3, NULL);
    sfRenderWindow_drawRectangleShape(game->window,
            game->ig.tower->rect.tower4, NULL);
}

static void check_rect(sfRectangleShape *rect, sfVector2i mouse
    , game_t *game, sfVector2f pos)
{
    if ((mouse.x >= pos.x && mouse.x <= pos.x + 290.0)
        && (mouse.y >= pos.y && mouse.y <= pos.y + 145.0))
        sfRectangleShape_setFillColor(rect, sfGreen);
    else
        sfRectangleShape_setFillColor(rect, sfTransparent);
}

static void set_color_blue(game_t *game)
{
    if (game->cursor.status == 1)
        sfRectangleShape_setFillColor(game->ig.tower->rect.tower1, sfBlue);
    if (game->cursor.status == 2)
        sfRectangleShape_setFillColor(game->ig.tower->rect.tower2, sfBlue);
    if (game->cursor.status == 3)
        sfRectangleShape_setFillColor(game->ig.tower->rect.tower3, sfBlue);
    if (game->cursor.status == 4)
        sfRectangleShape_setFillColor(game->ig.tower->rect.tower4, sfBlue);
}

void set_color_rect(game_t *game)
{
    if (game->cursor.status == 0) {
        check_rect(game->ig.tower->rect.tower1,
                sfMouse_getPositionRenderWindow(game->window),
                game,
                sfRectangleShape_getPosition(game->ig.tower->rect.tower1));
        check_rect(game->ig.tower->rect.tower2,
                sfMouse_getPositionRenderWindow(game->window),
                game,
                sfRectangleShape_getPosition(game->ig.tower->rect.tower2));
        check_rect(game->ig.tower->rect.tower3,
                sfMouse_getPositionRenderWindow(game->window),
                game,
                sfRectangleShape_getPosition(game->ig.tower->rect.tower3));
        check_rect(game->ig.tower->rect.tower4,
                sfMouse_getPositionRenderWindow(game->window),
                game,
                sfRectangleShape_getPosition(game->ig.tower->rect.tower4));
    }
    else
        set_color_blue(game);
}