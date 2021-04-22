/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** upgrade_tower
*/

#include "my_defender.h"

void upgrade_shop(game_t *game, sfVector2f pos, int i)
{
    int x = pos.x + 105;
    int y = pos.y;

    if (game->ig.tower[i].type == 4)
        game->ig.shop.cost = create_text(x, y, "100");
    if (game->ig.tower[i].type == 3)
        game->ig.shop.cost = create_text(x, y, "150");
    if (game->ig.tower[i].type == 2)
        game->ig.shop.cost = create_text(x, y, "150");
    if (game->ig.tower[i].type == 1)
        game->ig.shop.cost = create_text(x, y, "300");
    sfText_setCharacterSize(game->ig.shop.cost, 30);
    sfSprite_setPosition(game->ig.shop.view.sprite, pos);
    game->ig.shop.status = 1;
}

void check_upgrade(game_t *game, int x, int y, int i)
{
    if (game->event.type == sfEvtMouseButtonReleased
        && game->event.key.code == sfMouseLeft
        && game->ig.tower[i].type != 0
        && game->cursor.view.position.x >= x
        && game->cursor.view.position.x <= x + 145
        && game->cursor.view.position.y >= y
        && game->cursor.view.position.y <= y + 105) {
        if (game->ig.tower[i].type == 1)
            upgrade_shop(game, create_vector(x + 100, y - 30), i);
        if (game->ig.tower[i].type == 2)
            upgrade_shop(game, create_vector(x + 100, y - 30), i);
        if (game->ig.tower[i].type == 3)
            upgrade_shop(game, create_vector(x + 100, y - 30), i);
        if (game->ig.tower[i].type == 4)
            upgrade_shop(game, create_vector(x + 100, y - 30), i);
    }
}

void upgrade_tower(game_t *game, int x, int y, int i)
{
    if (game->cursor.status == 0 && game->event.key.code == sfMouseLeft
        && game->cursor.view.position.x >= x + 100
        && game->cursor.view.position.x <= x + 140
        && game->cursor.view.position.y >= y - 30
        && game->cursor.view.position.y <= y
        && game->ig.tower[i].type >= 1 && game->ig.tower[i].type <= 4) {
        check_type_of_tower(game, create_vector(x + 10, y - 80),
                "resources/game/tower4lvl2.png", i);
        check_type_of_tower(game, create_vector(x + 10, y - 80),
                "resources/game/tower3lvl2.png", i);
        check_type_of_tower(game, create_vector(x + 20, y - 80),
                "resources/game/tower2lvl2.png", i);
        check_type_of_tower(game, create_vector(x + 20, y - 80),
                "resources/game/tower1lvl2.png", i);
    }
}

void check_type_of_tower(game_t *game, sfVector2f pos, char *fp, int i)
{
    if (game->ig.tower[i].type == fp[20] - 48) {
        if (fp[20] - 48 == 4 && game->ig.shop.po_nb >= 100)
            up_tower_type_four(game, pos, fp, i);
        else if (fp[20] - 48 == 4)
            return;
        if (fp[20] - 48 == 3 && game->ig.shop.po_nb >= 150)
            up_tower_type_tree(game, pos, fp, i);
        else if (fp[20] - 48 == 3)
            return;
        if (fp[20] - 48 == 2 && game->ig.shop.po_nb >= 150)
            up_tower_type_two(game, pos, fp, i);
        else if (fp[20] - 48 == 2)
            return;
        if (fp[20] - 48 == 1 && game->ig.shop.po_nb >= 300)
            up_tower_type_one(game, pos, fp, i);
        else if (fp[20] - 48 == 1)
            return;
    }
}

void manage_upgrade(game_t *game)
{
    if (game->cursor.status == 0 && game->ig.shop.status == 0)
        display_shop(game);
    else if (game->cursor.status == 0 && game->ig.shop.status != 0) {
        upgrade_tower(game, 383, 220 - 40, 0);
        upgrade_tower(game, 383, 351 - 40, 1);
        upgrade_tower(game, 643, 483 - 40, 2);
        upgrade_tower(game, 902, 483 - 40, 3);
        upgrade_tower(game, 966, 320 - 40, 4);
        upgrade_tower(game, 1359, 255 - 40, 5);
        upgrade_tower(game, 1422, 418 - 40, 6);
        if (sfMouse_isButtonPressed(sfMouseLeft)
            && game->ig.shop.status != 0) {
            game->cursor.status = 0;
            game->ig.shop.status = 0;
            game->ig.shop.cost = create_text(0, 0, "");
        }
    }
}