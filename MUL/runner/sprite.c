/*
** EPITECH PROJECT, 2018
** MUL runner | sprite
** File description:
** The function that initialize the sprite
*/

#include "runner.h"

sprite_t *initialize_character(sprite_t *character)
{
    character = malloc(sizeof(sprite_t) * 3);
    if (character == NULL)
        return (NULL);
    character->texture = sfTexture_createFromFile("ressources/running.png"
                                                  , NULL);
    character->sprite = sfSprite_create();
    character->position.x = 125;
    character->position.y = 905;
    character->rect.top = 0;
    character->rect.left = 0;
    character->rect.width = 85;
    character->rect.height = 105;
    sfSprite_setPosition(character->sprite, character->position);
    return (character);
}

sprite_t *initialize_foreground(sprite_t *background)
{
    background = malloc(sizeof(sprite_t) * 2);
    if (background == NULL)
        return (NULL);
    background->texture = sfTexture_createFromFile("ressources/foreground.png"
                                                    , NULL);
    background->sprite = sfSprite_create();
    background->position.x = 0;
    background->position.y = 990;
    background->vector.x = 3;
    background->vector.y = 3;
    sfSprite_setScale(background->sprite, background->vector);
    sfSprite_setPosition(background->sprite, background->position);
    return (background);
}

sprite_t *initialize_parallax(sprite_t *parallax, char const *filepath)
{
    parallax = malloc(sizeof(sprite_t) * 2);
    if (parallax == NULL)
        return (NULL);
    parallax->texture = sfTexture_createFromFile(filepath, NULL);
    parallax->sprite = sfSprite_create();
    parallax->position.x = 0;
    parallax->position.y = 0;
    parallax->vector.x = 5;
    parallax->vector.y = 5;
    sfSprite_setScale(parallax->sprite, parallax->vector);
    sfSprite_setPosition(parallax->sprite, parallax->position);
    return (parallax);
}

sprite_t *initialize_infinite(sprite_t *parallax , char const *filepath)
{
    parallax = malloc(sizeof(sprite_t) * 2);
    if (parallax == NULL)
        return (NULL);
    parallax->texture = sfTexture_createFromFile(filepath, NULL);
    parallax->sprite = sfSprite_create();
    parallax->position.x = 1920;
    parallax->position.y = 0;
    parallax->vector.x = 5;
    parallax->vector.y = 5;
    sfSprite_setScale(parallax->sprite, parallax->vector);
    sfSprite_setPosition(parallax->sprite, parallax->position);
    return (parallax);
}

sprite_t *initialize_infinite2(sprite_t *parallax , char const *filepath)
{
    parallax = malloc(sizeof(sprite_t) * 2);
    if (parallax == NULL)
        return (NULL);
    parallax->texture = sfTexture_createFromFile(filepath, NULL);
    parallax->sprite = sfSprite_create();
    parallax->position.x = 1920;
    parallax->position.y = 990;
    parallax->vector.x = 3;
    parallax->vector.y = 3;
    sfSprite_setScale(parallax->sprite, parallax->vector);
    sfSprite_setPosition(parallax->sprite, parallax->position);
    return (parallax);
}