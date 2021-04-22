/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** my_defender
*/

#include "my_defender.h"

int my_defender(game_t *game)
{
    if (create_game(game) == 1)
        return (84);
    while (sfRenderWindow_isOpen(game->window) != 0 && game->ig.life_nb > 0) {
        display_game(game);
        while(sfRenderWindow_pollEvent(game->window, &game->event))
            manage_event_game(game);
    }
    if (game->ig.life_nb <= 0)
        destroy_in_game(game, 0);
    return (0);
}

int manage_event_game(game_t *game)
{
    manage_drag_and_drop(game);
    set_color_rect(game);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
        return (menu_pause(game));
}

void display_game(game_t *game)
{    
    sfRenderWindow_clear(game->window, sfBlack);
    display_tower_rect(game);
    sfRenderWindow_drawSprite(game->window, game->ig.backg.sprite, NULL);
    manage_minions(game);
    for (int i = 0; i < 7; i++)
        if (game->ig.tower[i].type != 0)
            shoot_tower(game, i);
    if (game->ig.shop.status != 0)
        sfRenderWindow_drawSprite(game->window,
                game->ig.shop.view.sprite, NULL);
    calcul_score(game);
    display_text(game);
    display_cursor(game);
    sfRenderWindow_display(game->window);
}

void manage_minions(game_t *game)
{
    float seconds = params_clock(seconds, game->ig.spawn);

    for (int i = game->ig.nb_minions; i >= 0; i--) {
        path_minion(game, i);
        position_life(game, i);
        sfRenderWindow_drawSprite(game->window,
                game->ig.charact[i].minion.sprite, NULL);
    }
    if (seconds > 600 / 60.0 && game->ig.nb_minions < 99) {
        game->ig.nb_minions++;
        initialize_charact(&game->ig.charact[game->ig.nb_minions],
                game->window);
        sfClock_restart(game->ig.spawn);
    }
}
