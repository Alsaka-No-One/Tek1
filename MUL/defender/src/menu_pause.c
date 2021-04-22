/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** menu_pause
*/

#include "my_defender.h"

int manage_event_menu_pause(game_t *game, int *status)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtMouseButtonReleased
            && game->event.key.code == sfMouseLeft
            && game->cursor.view.position.x >= 800
            && game->cursor.view.position.x <= 1150
            && game->cursor.view.position.y >= 250
            && game->cursor.view.position.y <= 405)
            *status = 1;
        if (manage_event_menu_pause_two(game, status) == 0)
            return (0);
        manage_event_menu_pause_tree(game);
    }
    return (1);
}

int manage_event_menu_pause_two(game_t *game, int *status)
{
    if (game->event.type == sfEvtMouseButtonReleased
        && game->event.key.code == sfMouseLeft
        && game->cursor.view.position.x >= 800
        && game->cursor.view.position.x <= 1150
        && game->cursor.view.position.y >= 450
        && game->cursor.view.position.y <= 605) {
        destroy_in_game(game, 1);
        if (menu(game) != 0)
            return (my_defender(game));
        else
            *status = 1;
    }
    return (1);
}

int manage_event_menu_pause_tree(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonReleased
        && game->event.key.code == sfMouseLeft
        && game->cursor.view.position.x >= 800
        && game->cursor.view.position.x <= 1150
        && game->cursor.view.position.y >= 650
        && game->cursor.view.position.y <= 805) {
        sfRenderWindow_close(game->window);
        destroy_in_game(game, 1);
    }
    return (1);
}

int menu_pause(game_t *game)
{
    int status = 0;

    create_pause(game);
    while (sfRenderWindow_isOpen(game->window) != 0 &&  status == 0) {
            display_menu_pause(game);
            if (manage_event_menu_pause(game, &status) == 0)
                return (0);
    }
    return (1);
}

void create_pause(game_t *game)
{
    initialize_draw_sprite(&game->pause.bg, game->window,
            "resources/menu/bg_menu_pause.png");
    game->pause.resume = create_text(870, 300, "RESUME");
    game->pause.quit = create_text(900, 700, "QUIT");
    game->pause.back = create_text(900, 500, "BACK");
    game->pause.button.resume = init_button_text(game->pause.button.resume,
            create_vector(800.0, 250.0),
            create_vector(350.0, 155.0),
            game->pause.button.resume_text);
    game->pause.button.back = init_button_text(game->pause.button.back,
            create_vector(800.0, 450.0),
            create_vector(350.0, 155.0),
            game->pause.button.back_text);
    game->pause.button.quit = init_button_text(game->pause.button.quit,
            create_vector(800.0, 650.0),
            create_vector(350.0, 155.0),
            game->pause.button.quit_text);
}