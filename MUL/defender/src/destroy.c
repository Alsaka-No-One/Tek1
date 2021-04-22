/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** destroy_all
*/

#include "my_defender.h"

void destroy_pause(game_t *game)
{
    sfRectangleShape_destroy(game->pause.button.resume);
    sfRectangleShape_destroy(game->pause.button.quit);
    sfRectangleShape_destroy(game->pause.button.back);
    sfTexture_destroy(game->pause.bg.texture);
    sfSprite_destroy(game->pause.bg.sprite);
    sfText_destroy(game->pause.resume);
    sfText_destroy(game->pause.quit);
    sfText_destroy(game->pause.back);
}

void destroy_all_menu(game_t *game)
{
    destroy_menu(game);
    sfSprite_destroy(game->cursor.d_and_d.sprite);
    sfTexture_destroy(game->cursor.d_and_d.texture);
    sfTexture_destroy(game->cursor.view.texture);
    sfSprite_destroy(game->cursor.view.sprite);
}

void destroy_in_game(game_t *game, int status)
{
    sfTexture_destroy(game->ig.backg.texture);
    sfSprite_destroy(game->ig.backg.sprite);
    sfText_destroy(game->ig.score);
    sfClock_destroy(game->ig.score_c);
    sfText_destroy(game->ig.life);
    sfMusic_destroy(game->ig.music);
    sfMusic_destroy(game->ig.place_td);
    sfMusic_destroy(game->ig.up_td);
    sfText_destroy(game->ig.shop.cost);
    sfText_destroy(game->ig.shop.po);
    sfTexture_destroy(game->ig.shop.view.texture);
    sfSprite_destroy(game->ig.shop.view.sprite);
    sfClock_destroy(game->ig.spawn);
    destroy_loop(game);
    free(game->ig.tower);
    free(game->ig.charact);
    if (status == 1)
        destroy_pause(game);
}

void destroy_menu(game_t *game)
{
    sfText_destroy(game->menu.tuto_text);
    sfRectangleShape_destroy(game->menu.button.rect);
    sfRectangleShape_destroy(game->menu.button.quit_rect);
    sfRectangleShape_destroy(game->menu.button.tuto_rect);
    sfText_destroy(game->menu.text);
    sfText_destroy(game->menu.quit_text);
    sfTexture_destroy(game->menu.background.texture);
    sfSprite_destroy(game->menu.background.sprite);
    sfTexture_destroy(game->menu.title.texture);
    sfSprite_destroy(game->menu.title.sprite);
    sfMusic_destroy(game->menu.music);
}

void destroy_loop(game_t *game)
{
    sfSprite_destroy(game->cursor.d_and_d.sprite);
    sfTexture_destroy(game->cursor.d_and_d.texture);
    sfTexture_destroy(game->cursor.view.texture);
    sfSprite_destroy(game->cursor.view.sprite);
    for (int i = 0; i < 7; i++)
        if (game->ig.tower[i].type != 0) {
            sfTexture_destroy(game->ig.tower[i].view.texture);
            sfSprite_destroy(game->ig.tower[i].view.sprite);
            sfTexture_destroy(game->ig.tower[i].bullet.view.texture);
            sfSprite_destroy(game->ig.tower[i].bullet.view.sprite);
            sfClock_destroy(game->ig.tower[i].clock);
            sfMusic_destroy(game->ig.tower[i].hit);
        }
    for (int i = game->ig.nb_minions; i >= 0; i--) {
        sfTexture_destroy(game->ig.charact[i].minion.texture);
        sfSprite_destroy(game->ig.charact[i].minion.sprite);
        sfClock_destroy(game->ig.charact[i].anim);
        sfMusic_destroy(game->ig.charact[i].death);
    }
    destroy2(game);
}