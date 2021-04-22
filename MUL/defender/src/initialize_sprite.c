/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** initialize_sprite
*/

#include "my_defender.h"

void initialize_draw_sprite(sprite_t *object, sfRenderWindow *window, char *fp)
{
    object->texture = sfTexture_createFromFile(fp, NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setPosition(object->sprite, object->position);
    sfRenderWindow_drawSprite(window, object->sprite, NULL);
}

void initialize_charact_two(charact_t *charact, sfRenderWindow *window)
{
    if (charact->type == 2) {
        charact->minion.texture =
                sfTexture_createFromFile("resources/game/rock_lee.png", NULL);
        charact->anim = sfClock_create();
        charact->minion.sprite = sfSprite_create();
        charact->minion.position.x = 130.0;
        charact->minion.position.y = 140.0;
        charact->rect.width = 47;
        charact->rect.height = 43;
        charact->life = 5;
    }
    charact->rect.left = 0;
    charact->rect.top = 0;
    charact->death = sfMusic_createFromFile("resources/sound/death.ogg");
    sfSprite_setTexture(charact->minion.sprite,
            charact->minion.texture, sfTrue);
    sfSprite_setTextureRect(charact->minion.sprite, charact->rect);
    sfSprite_setPosition(charact->minion.sprite, charact->minion.position);
}

void initialize_charact(charact_t *charact, sfRenderWindow *window)
{
    if (charact->type == 1) {
        charact->minion.texture =
                sfTexture_createFromFile("resources/game/evoli.png", NULL);
        charact->anim = sfClock_create();
        charact->minion.sprite = sfSprite_create();
        charact->minion.position.x = 130.0;
        charact->minion.position.y = 140.0;
        charact->rect.width = 49;
        charact->rect.height = 25;
        charact->life = 10;
        sfSprite_setScale(charact->minion.sprite, create_vector(2.0, 2.0));
    }
    initialize_charact_two(charact, window);
}