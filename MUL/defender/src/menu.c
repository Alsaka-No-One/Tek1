/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** menu
*/

#include "my_defender.h"

int menu(game_t *game)
{
    int status = 0;

    create_menu(game);
    while (status == 0 && sfRenderWindow_isOpen(game->window) != 0) {
        manage_display_menu(game);
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            status = manage_event_menu(game);
    }
    if (status == 2) {
        sfRenderWindow_close(game->window);
        destroy_all_menu(game);
        status = 0;
    }
    else
        destroy_menu(game);
    return (status);
}

static void manage_display_menu2(game_t *game)
{
    set_color_text(game->menu.quit_text,
            sfRectangleShape_getGlobalBounds(game->menu.button.quit_rect),
            sfRectangleShape_getPosition(game->menu.button.quit_rect),
            sfMouse_getPositionRenderWindow(game->window));
    sfRenderWindow_drawRectangleShape(game->window,
            game->menu.button.quit_rect, NULL);
    set_color_text(game->menu.tuto_text,
            sfRectangleShape_getGlobalBounds(game->menu.button.tuto_rect),
            sfRectangleShape_getPosition(game->menu.button.tuto_rect),
            sfMouse_getPositionRenderWindow(game->window));
    sfRenderWindow_drawRectangleShape(game->window,
            game->menu.button.tuto_rect, NULL);
    sfRenderWindow_drawText(game->window, game->menu.quit_text, NULL);
    sfRenderWindow_drawText(game->window, game->menu.tuto_text, NULL);
}

void manage_display_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window,
            game->menu.background.sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
            game->menu.title.sprite, NULL);
    set_color_text(game->menu.text,
            sfRectangleShape_getGlobalBounds(game->menu.button.rect),
            sfRectangleShape_getPosition(game->menu.button.rect),
            sfMouse_getPositionRenderWindow(game->window));
    sfRenderWindow_drawRectangleShape(game->window,
            game->menu.button.rect, NULL);
    sfRenderWindow_drawText(game->window, game->menu.text, NULL);
    manage_display_menu2(game);
    display_cursor(game);
    sfRenderWindow_display(game->window);
}

int manage_event_menu(game_t *game)
{
    if (game->event.key.code == sfMouseLeft
        && game->cursor.view.position.x >= 800
        && game->cursor.view.position.x <= 1150
        && game->cursor.view.position.y >= 450
        && game->cursor.view.position.y <= 605) {
        return (1);
    }
    if (game->event.key.code == sfMouseLeft
        && game->cursor.view.position.x >= 800
        && game->cursor.view.position.x <= 1150
        && game->cursor.view.position.y >= 650
        && game->cursor.view.position.y <= 805)
        return (display_tuto(game));
    if (game->event.key.code == sfMouseLeft
        && game->cursor.view.position.x >= 800
        && game->cursor.view.position.x <= 1150
        && game->cursor.view.position.y >= 850
        && game->cursor.view.position.y <= 1005)
        return (2);
    return (0);
}