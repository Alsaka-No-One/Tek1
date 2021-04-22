/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** tower_attack
*/

#include "my_defender.h"

void minions_death(game_t *game, int j, int *k, int i)
{
    calcul_bullet(game, i, j);
    game->ig.charact[j].life -= game->ig.tower[i].shoot;
    size_life(game, j);
    sfMusic_play(game->ig.tower[i].hit);
    sfClock_restart(game->ig.tower[i].clock);
    *k = 1;
    if (game->ig.nb_minions >= 0 && game->ig.charact[j].life <= 0) {
        game->ig.charact[j].minion.position = create_vector(130, 140);
        sfSprite_setPosition(game->ig.charact[j].minion.sprite,
            game->ig.charact[j].minion.position);
        sfMusic_play(game->ig.charact[j].death);
        if (game->ig.charact[j].type == 1) {
            game->ig.charact[j].life = 10;
            game->ig.shop.po_nb += 5;
        } else {
            game->ig.charact[j].life = 5;
            game->ig.shop.po_nb += 10;
        }
        size_life(game, j);
    }
}

void calcul_bullet(game_t *game, int i, int j)
{
    sfVector2f pos_tower = sfSprite_getPosition(game->ig.tower[i].view.sprite);
    game->ig.tower[i].bullet.view.position.x = pos_tower.x + 70;
    game->ig.tower[i].bullet.view.position.y = pos_tower.y + 130;
    sfSprite_setPosition(game->ig.tower[i].bullet.view.sprite,
            game->ig.tower[i].bullet.view.position);
    game->ig.tower[i].bullet.nb_m = j;
    game->ig.tower[i].bullet.status = 7;
}

void calcul_bullet_move(game_t *game, int i)
{
    sfVector2f move;
    sfVector2f pos;

    pos.x =
        (game->ig.charact[game->ig.tower[i].bullet.nb_m].minion.position.x
        + game->ig.tower[i].bullet.view.position.x + 45) / 2;
    pos.y =
        (game->ig.charact[game->ig.tower[i].bullet.nb_m].minion.position.y
        + game->ig.tower[i].bullet.view.position.y + 15) / 2;
    move.x = pos.x - game->ig.tower[i].bullet.view.position.x;
    move.y = pos.y - game->ig.tower[i].bullet.view.position.y;
    game->ig.tower[i].bullet.view.position.x += move.x;
    game->ig.tower[i].bullet.view.position.y += move.y;
    sfSprite_move(game->ig.tower[i].bullet.view.sprite, move);
    sfRenderWindow_drawSprite(game->window,
                game->ig.tower[i].bullet.view.sprite, NULL);
    game->ig.tower[i].bullet.status--;
}

void draw_bullet(game_t *game, int i)
{
    if (game->ig.tower[i].bullet.status != 0) {
        if (game->ig.charact[game->ig.tower[i].bullet.nb_m].minion.position.x
            <= 150) {
            game->ig.tower[i].bullet.status = 0;
            return;
        }
    calcul_bullet_move(game, i);
    }
}

void shoot_tower(game_t *game, int i)
{
    int k = 0;
    float seconds = params_clock(seconds, game->ig.tower[i].clock);

    sfRenderWindow_drawSprite(game->window,
                game->ig.tower[i].view.sprite, NULL);
    draw_bullet(game, i);
    for (int j = game->ig.nb_minions; j >= 0; j--)
        if (k == 0 && game->ig.charact[j].minion.position.x
            >= game->ig.tower[i].range.x &&
            game->ig.charact[j].minion.position.y >=
            game->ig.tower[i].range.y &&
            game->ig.charact[j].minion.position.x <=
            game->ig.tower[i].range_sd.x
            && game->ig.charact[j].minion.position.y
            <= game->ig.tower[i].range_sd.y
            && seconds > game->ig.tower[i].vitesse / 60.0)
            minions_death(game, j, &k, i);
}