/*
** EPITECH PROJECT, 2019
** defender
** File description:
** bootstrap
*/

#include "my_defender.h"

sfRectangleShape *init_button(sfRectangleShape *rect,
        sfVector2f position, sfVector2f size)
{
    rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, position);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    return (rect);
}

sfRectangleShape *init_button_life(sfRectangleShape *rect,
        sfVector2f position, sfVector2f size)
{
    rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, position);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, sfRed);
    return (rect);
}

sfRectangleShape *init_button_text(sfRectangleShape *rect,
        sfVector2f position, sfVector2f size, sfTexture *texture)
{
    texture = sfTexture_createFromFile("resources/menu/bs.png", NULL);
    rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, position);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setTexture(rect, texture, sfTrue);
    return (rect);
}

bool button_is_clicked(button_t *button, sfVector2i click_position)
{
    sfFloatRect size = sfRectangleShape_getGlobalBounds(button->rect);
    sfVector2f position = sfRectangleShape_getPosition(button->rect);

    if ((click_position.x >= position.x
        && click_position.x <= position.x + size.width)
        && (click_position.y >= position.y
        && click_position.y <= position.y + size.height))
        return (true);
    return (false);
}
