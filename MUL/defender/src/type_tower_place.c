/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** type_tower_place
*/

#include "my_defender.h"

void tower_type_four(game_t *game, sfVector2f pos, int i, char *fp)
{
    game->ig.shop.po_nb -= 50;
    game->ig.tower[i].shoot = 2;
    game->ig.tower[i].vitesse = 60;
    game->ig.tower[i].clock = sfClock_create();
    game->ig.tower[i].hit = sfMusic_createFromFile("resources/sound/bow.ogg");
    game->ig.tower[i].range = create_vector(pos.x - 150, pos.y - 100);
    game->ig.tower[i].range_sd = create_vector(pos.x + 225, pos.y + 225);
    sfMusic_play(game->ig.place_td);
    initialize_draw_sprite(&game->ig.tower[i].view, game->window, fp);
    initialize_draw_sprite(&game->ig.tower[i].bullet.view, game->window,
            "resources/game/bullet.png");
    game->ig.tower[i].bullet.status = 0;
    sfSprite_setPosition(game->ig.tower[i].view.sprite, pos);
    game->ig.tower[i].type = fp[20] - 48;
}

void tower_type_tree(game_t *game, sfVector2f pos, int i, char *fp)
{
    game->ig.shop.po_nb -= 75;
    game->ig.tower[i].shoot = 1;
    game->ig.tower[i].vitesse = 20;
    game->ig.tower[i].clock = sfClock_create();
    game->ig.tower[i].hit =
            sfMusic_createFromFile("resources/sound/shoot.ogg");
    game->ig.tower[i].range = create_vector(pos.x - 125, pos.y - 75);
    game->ig.tower[i].range_sd = create_vector(pos.x + 200, pos.y + 200);
    sfMusic_play(game->ig.place_td);
    initialize_draw_sprite(&game->ig.tower[i].view, game->window, fp);
    initialize_draw_sprite(&game->ig.tower[i].bullet.view, game->window,
            "resources/game/bullet.png");
    game->ig.tower[i].bullet.status = 0;
    sfSprite_setPosition(game->ig.tower[i].view.sprite, pos);
    game->ig.tower[i].type = fp[20] - 48;
}

void tower_type_two(game_t *game, sfVector2f pos, int i, char *fp)
{
    game->ig.shop.po_nb -= 75;
    game->ig.tower[i].shoot = 5;
    game->ig.tower[i].vitesse = 100;
    game->ig.tower[i].clock = sfClock_create();
    game->ig.tower[i].hit =
            sfMusic_createFromFile("resources/sound/shoot2.ogg");
    game->ig.tower[i].range = create_vector(pos.x - 280, pos.y - 230);
    game->ig.tower[i].range_sd = create_vector(pos.x + 355, pos.y + 355);
    sfMusic_play(game->ig.place_td);
    initialize_draw_sprite(&game->ig.tower[i].view, game->window, fp);
    initialize_draw_sprite(&game->ig.tower[i].bullet.view, game->window,
            "resources/game/bullet.png");
    game->ig.tower[i].bullet.status = 0;
    sfSprite_setPosition(game->ig.tower[i].view.sprite, pos);
    game->ig.tower[i].type = fp[20] - 48;
}

void tower_type_one(game_t *game, sfVector2f pos, int i, char *fp)
{
    game->ig.shop.po_nb -= 150;
    game->ig.tower[i].shoot = 3;
    game->ig.tower[i].vitesse = 40;
    game->ig.tower[i].clock = sfClock_create();
    game->ig.tower[i].hit =
            sfMusic_createFromFile("resources/sound/laser.ogg");
    game->ig.tower[i].range = create_vector(pos.x - 300, pos.y - 250);
    game->ig.tower[i].range_sd = create_vector(pos.x + 350, pos.y + 350);
    sfMusic_play(game->ig.place_td);
    initialize_draw_sprite(&game->ig.tower[i].view, game->window, fp);
    initialize_draw_sprite(&game->ig.tower[i].bullet.view, game->window,
            "resources/game/bullet.png");
    game->ig.tower[i].bullet.status = 0;
    sfSprite_setPosition(game->ig.tower[i].view.sprite, pos);
    game->ig.tower[i].type = fp[20] - 48;
}