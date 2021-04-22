/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create_game
*/

#include "my_defender.h"

int create_game(game_t *game)
{
    game->ig.tower = malloc(sizeof(tower_t) * 7);
    game->ig.charact = malloc(sizeof(charact_t) * 100);
    if (game->ig.tower == NULL || game->ig.charact == NULL)
        return (1);
    for (int i = 0; i < 7; i++)
        game->ig.tower[i].type = 0;
    for (int i = 0; i < 100; i++) {
        if (i % 4 == 3)
            game->ig.charact[i].type = 2;
        else
            game->ig.charact[i].type = 1;
        life_rect(game, i);
    }
    game->ig.nb_minions = -1;
    initialize_draw_sprite(&game->ig.backg, game->window,
            "resources/game/bg_game.png");
    initialize_draw_sprite(&game->ig.shop.view, game->window,
            "resources/game/upgrade.png");
    create_game_two(game);
    return (0);
}

void create_game_two(game_t *game)
{
    game->ig.shop.status = 0;
    game->ig.music = sfMusic_createFromFile("resources/sound/song_game.ogg");
    sfMusic_setLoop(game->ig.music, sfTrue);
    sfMusic_play(game->ig.music);
    sfSprite_setPosition(game->ig.backg.sprite, create_vector(0, 0));
    game->ig.shop.po = create_text(140, 960, "50");
    game->ig.shop.po_nb = 100;
    game->ig.shop.cost = create_text(0, 0, "");
    game->ig.score = create_text(170, 1015, "score : 0");
    game->ig.score_nb = 0;
    game->ig.life = create_text(160, 885, "20");
    game->ig.life_nb = 20;
    sfText_setCharacterSize(game->ig.shop.po, 40);
    sfText_setCharacterSize(game->ig.score, 40);
    tower_rect(game);
    game->ig.spawn = sfClock_create();
    game->ig.score_c = sfClock_create();
    game->ig.place_td = sfMusic_createFromFile("resources/sound/place_td.ogg");
    game->ig.up_td = sfMusic_createFromFile("resources/sound/up.ogg");
}