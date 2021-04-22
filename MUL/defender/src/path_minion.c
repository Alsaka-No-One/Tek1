/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** path_minion
*/

#include "my_defender.h"

static void move_minion_two(game_t *game, int *status, int i)
{
    if (*status == 2) {
        if (game->ig.charact[i].type == 1) {
            sfSprite_move(game->ig.charact[i].minion.sprite
                        , create_vector(1.0, -0.5));
            game->ig.charact[i].minion.position.x += 1;
            game->ig.charact[i].minion.position.y -= 0.5;
        } else {
            sfSprite_move(game->ig.charact[i].minion.sprite
                        , create_vector(2.0, -1));
            game->ig.charact[i].minion.position.x += 2;
            game->ig.charact[i].minion.position.y -= 1;
        }
    }
}

static void move_minion(game_t *game, int status, int i)
{
    if (status == 1) {
        if (game->ig.charact[i].type == 1) {
            sfSprite_move(game->ig.charact[i].minion.sprite
                        , create_vector(1.0, 0.5));
            game->ig.charact[i].minion.position.x += 1;
            game->ig.charact[i].minion.position.y += 0.5;
        } else {
            sfSprite_move(game->ig.charact[i].minion.sprite
                        , create_vector(2.0, 1));
            game->ig.charact[i].minion.position.x += 2;
            game->ig.charact[i].minion.position.y += 1;
        }
    }
    move_minion_two(game, &status, i);
}

static void anim_minion(game_t *game, int i)
{
    float seconds;

    seconds = params_clock(seconds, game->ig.charact[i].anim);
    if (seconds > 9.0 / 60.0) {
        game->ig.charact[i].rect.left += 49;
        if (game->ig.charact[i].rect.left >= 196)
            game->ig.charact[i].rect.left = 0;
    sfSprite_setTextureRect(game->ig.charact[i].minion.sprite
                        , game->ig.charact[i].rect);
    sfClock_restart(game->ig.charact[i].anim);
    }
}

void hit_base(game_t *game, int i)
{
    if (game->ig.charact[i].type == 1)
        game->ig.life_nb -= 1;
    if (game->ig.charact[i].type == 2)
        game->ig.life_nb -= 2;
}

void path_minion(game_t *game, int i)
{
    if (game->ig.charact[i].minion.position.x < 800.0) {
        move_minion(game, 1, i);
    } else if (game->ig.charact[i].minion.position.x >= 800.0
                && game->ig.charact[i].minion.position.x < 1242.0) {
        move_minion(game, 2, i);
    }
    if (game->ig.charact[i].minion.position.x >= 1242.0
        && game->ig.charact[i].minion.position.x < 1685.0) {
        move_minion(game, 1, i);
    }
    if (game->ig.charact[i].minion.position.x >= 1685.0) {
        sfSprite_setPosition(game->ig.charact[i].minion.sprite
                            , create_vector(130.0, 140.0));
        game->ig.charact[i].minion.position.x = 130;
        game->ig.charact[i].minion.position.y = 140;
        hit_base(game, i);
    }
    anim_minion(game, i);
}