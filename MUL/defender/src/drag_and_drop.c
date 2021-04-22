/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** drag_and_drop
*/

#include "my_defender.h"

void display_shop(game_t *game)
{
    check_upgrade(game, 383, 220 - 40, 0);
    check_upgrade(game, 383, 351 - 40, 1);
    check_upgrade(game, 643, 483 - 40, 2);
    check_upgrade(game, 902, 483 - 40, 3);
    check_upgrade(game, 966, 320 - 40, 4);
    check_upgrade(game, 1359, 255 - 40, 5);
    check_upgrade(game, 1422, 418 - 40, 6);
}

void manage_drag_and_drop(game_t *game)
{
    manage_upgrade(game);
    if (game->cursor.status == 0) {
        select_drag_and_drop(game, 600, 1, "resources/game/tower4lvl1.png");
        select_drag_and_drop(game, 925, 2, "resources/game/tower3lvl1.png");
        select_drag_and_drop(game, 1250, 3, "resources/game/tower2lvl1.png");
        select_drag_and_drop(game, 1575, 4, "resources/game/tower1lvl1.png");
    }
    else if (game->cursor.status != 0) {
        place_tower(game, 383, 220 - 40, 0);
        place_tower(game, 383, 351 - 40, 1);
        place_tower(game, 643, 483 - 40, 2);
        place_tower(game, 902, 483 - 40, 3);
        place_tower(game, 966, 320 - 40, 4);
        place_tower(game, 1359, 255 - 40, 5);
        place_tower(game, 1422, 418 - 40, 6);
        if (game->event.key.code == sfMouseLeft) {
            game->cursor.status = 0;
            game->ig.shop.status = 0;
        }
    }
}

void place_tower(game_t *game, int x, int y, int i)
{
    if (game->event.key.code == sfMouseLeft && game->ig.tower[i].type == 0
        && game->cursor.view.position.x >= x
        && game->cursor.view.position.x <= x + 145
        && game->cursor.view.position.y >= y
        && game->cursor.view.position.y <= y + 105) {
        if (game->cursor.status == 1 && game->ig.shop.po_nb >= 50)
            select_tower(game, create_vector(x + 10, y - 80), i,
                    "resources/game/tower4lvl1.png");
        if (game->cursor.status == 2 && game->ig.shop.po_nb >= 75)
            select_tower(game, create_vector(x + 10, y - 80), i,
                    "resources/game/tower3lvl1.png");
        if (game->cursor.status == 3 && game->ig.shop.po_nb >= 75)
            select_tower(game, create_vector(x + 20, y - 80), i,
                    "resources/game/tower2lvl1.png");
        if (game->cursor.status == 4 && game->ig.shop.po_nb >= 150)
            select_tower(game, create_vector(x + 20, y - 80), i,
                    "resources/game/tower1lvl1.png");
    }
}

void select_tower(game_t *game, sfVector2f pos, int i, char *fp)
{
    if (fp[20] - 48 == 4)
        tower_type_four(game, pos, i, fp);
    if (fp[20] - 48 == 3)
        tower_type_tree(game, pos, i, fp);
    if (fp[20] - 48 == 2)
        tower_type_two(game, pos, i, fp);
    if (fp[20] - 48 == 1)
        tower_type_one(game, pos, i, fp);
}

void select_drag_and_drop(game_t *game, int x, int status, char *fp)
{
    if (game->event.key.code == sfMouseLeft
        && game->cursor.view.position.x >= x
        && game->cursor.view.position.x <= x + 290
        && game->cursor.view.position.y >= 900
        && game->cursor.view.position.y <= 1045) {
        game->cursor.status = status;
        initialize_draw_sprite(&game->cursor.d_and_d, game->window, fp);
    }
}