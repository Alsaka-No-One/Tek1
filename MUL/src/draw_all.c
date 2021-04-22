/*
** EPITECH PROJECT, 2018
** MUL my_hunter | draw_all
** File description:
** The function to draw_all
*/

#include "../include/my_hunter.h"

sfIntRect draw_all(background_t *back, sfRenderWindow *window, sprite_t *duck, sfIntRect rect)
{
    sfVector2f offset;

    draw_sprite_back(back, window);
    sfSprite_setTextureRect(duck->sprite, rect);
    draw_sprite_animal(duck, window);
    moove_bird(duck, offset, duck->nb);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
    return (rect);
}
