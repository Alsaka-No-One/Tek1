/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create_menu
*/

#include "my_defender.h"

static void create_menu2(game_t *game)
{
    game->menu.button.rect = init_button_text(game->menu.button.rect,
            create_vector(800.0, 450.0),
            create_vector(350.0, 155.0)
            , game->menu.button.texture);
    game->menu.button.quit_rect = init_button_text(game->menu.button.quit_rect,
            create_vector(800.0, 650.0),
            create_vector(350.0, 155.0),
            game->menu.button.texture_quit);
    game->menu.button.tuto_rect = init_button_text(game->menu.button.tuto_rect,
            create_vector(800.0, 850.0),
            create_vector(350.0, 155.0),
            game->menu.button.texture_tuto);
}

void create_menu(game_t *game)
{
    game->cursor = create_cursor(game->window);
    game->menu.title.position = create_vector(570, 150);
    game->menu.background.position = create_vector(0, 0);
    initialize_draw_sprite(&game->menu.background,
            game->window, "resources/menu/bg_menu.png");
    game->menu.music = sfMusic_createFromFile("resources/sound/song_menu.ogg");
    sfMusic_setLoop(game->menu.music, sfTrue);
    sfMusic_play(game->menu.music);
    initialize_draw_sprite(&game->menu.title,
            game->window, "resources/menu/title.png");
    game->menu.text = create_text(920, 500, "PLAY");
    game->menu.quit_text = create_text(915, 700, "TUTO");
    game->menu.tuto_text = create_text(915, 900, "QUIT");
    create_menu2(game);
}