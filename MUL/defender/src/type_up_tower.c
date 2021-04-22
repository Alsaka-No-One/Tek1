/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** type_up_tower
*/

#include "my_defender.h"

void up_tower_type_four(game_t *game, sfVector2f pos, char *fp, int i)
{
    game->ig.shop.po_nb -= 100;
    game->ig.tower[i].shoot = 3;
    game->ig.tower[i].vitesse = 55;
    game->ig.tower[i].range = create_vector(pos.x - 175, pos.y - 125);
    game->ig.tower[i].range_sd = create_vector(pos.x + 250, pos.y + 250);
    sfMusic_play(game->ig.up_td);
    initialize_draw_sprite(&game->ig.tower[i].view, game->window, fp);
    sfSprite_setPosition(game->ig.tower[i].view.sprite, pos);
    game->ig.tower[i].type += 4;
    game->ig.shop.status = 0;
    game->ig.shop.cost = create_text(0, 0, "");
}

void up_tower_type_tree(game_t *game, sfVector2f pos, char *fp, int i)
{
    game->ig.shop.po_nb -= 150;
    game->ig.tower[i].shoot = 1;
    game->ig.tower[i].vitesse = 15;
    game->ig.tower[i].range = create_vector(pos.x - 125, pos.y - 75);
    game->ig.tower[i].range_sd = create_vector(pos.x + 200, pos.y + 200);
    sfMusic_play(game->ig.up_td);
    initialize_draw_sprite(&game->ig.tower[i].view, game->window, fp);
    sfSprite_setPosition(game->ig.tower[i].view.sprite, pos);
    game->ig.tower[i].type += 4;
    game->ig.shop.status = 0;
    game->ig.shop.cost = create_text(0, 0, "");
}

void up_tower_type_two(game_t *game, sfVector2f pos, char *fp, int i)
{
    game->ig.shop.po_nb -= 150;
    game->ig.tower[i].shoot = 7;
    game->ig.tower[i].vitesse = 110;
    game->ig.tower[i].range = create_vector(pos.x - 425, pos.y - 375);
    game->ig.tower[i].range_sd = create_vector(pos.x + 500, pos.y + 500);
    sfMusic_play(game->ig.up_td);
    initialize_draw_sprite(&game->ig.tower[i].view, game->window, fp);
    sfSprite_setPosition(game->ig.tower[i].view.sprite, pos);
    game->ig.tower[i].type += 4;
    game->ig.shop.status = 0;
    game->ig.shop.cost = create_text(0, 0, "");
}

void up_tower_type_one(game_t *game, sfVector2f pos, char *fp, int i)
{
    game->ig.shop.po_nb -= 300;
    game->ig.tower[i].shoot = 5;
    game->ig.tower[i].vitesse = 35;
    game->ig.tower[i].range = create_vector(pos.x - 350, pos.y - 300);
    game->ig.tower[i].range_sd = create_vector(pos.x + 400, pos.y + 400);
    sfMusic_play(game->ig.up_td);
    initialize_draw_sprite(&game->ig.tower[i].view, game->window, fp);
    sfSprite_setPosition(game->ig.tower[i].view.sprite, pos);
    game->ig.tower[i].type += 4;
    game->ig.shop.status = 0;
    game->ig.shop.cost = create_text(0, 0, "");
}