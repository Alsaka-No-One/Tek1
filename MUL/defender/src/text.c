/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** text
*/

#include "my_defender.h"

sfText *set_color_text(sfText *text, sfFloatRect size,
        sfVector2f r_pos, sfVector2i mouse)
{
    if ((mouse.x >= r_pos.x && mouse.x <= r_pos.x + size.width)
        && (mouse.y >= r_pos.y && mouse.y <= r_pos.y + size.height))
        sfText_setColor(text, sfGreen);
    else
        sfText_setColor(text, sfRed);
    return (text);
}

sfText *create_text(int pos_x, int pos_y, char *word)
{
    sfFont *font = NULL;
    sfText *text = NULL;
    sfVector2f position = create_vector(pos_x, pos_y);

    font = sfFont_createFromFile("resources/ariali.ttf");
    text = sfText_create();
    sfText_setString(text, word);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, position);
    return (text);
}

void display_text(game_t *game)
{
    int_to_char(game->ig.shop.po_nb, game->ig.shop.po, game);
    int_to_char(game->ig.life_nb, game->ig.life, game);
    int_to_char(game->ig.score_nb, game->ig.score, game);
    sfRenderWindow_drawText(game->window, game->ig.shop.cost, NULL);
}