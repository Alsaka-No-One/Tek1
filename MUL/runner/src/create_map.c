/*
** EPITECH PROJECT, 2019
** MUL runner | create map
** File description:
** The function in order to create the map
*/

#include "runner.h"

void create_box(sfRenderWindow *window, sfVector2f position)
{
    sfTexture *texture = sfTexture_createFromFile("ressources/bloc.png"
                                                    , NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f vector;
    sfVector2f offset;

    vector.x = 2;
    vector.y = 2;
    offset.x = -10;
    sfSprite_setScale(sprite, vector);
    sfSprite_setPosition(sprite, position);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_move(sprite, offset);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void create_map(sfRenderWindow *window, char **map)
{
    sfVector2f position;
    int i = 0;
    int j = 0;

    position.x = 500;
    position.y = 612;
    while (j < 4) {
        if (i == 100) {
            i = 0;
            position.x = 500;
            j++;
            position.y += 96;
        }
        if (map[j][i] == '1')
            create_box(window, position);
        i++;
        position.x += 96;
    }
}