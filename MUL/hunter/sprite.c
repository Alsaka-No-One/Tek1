/*
** EPITECH PROJECT, 2018
** MUL hunter | spawn_bird
** File description:
** The function to make bird spawn
*/

#include "include/my_hunter.h"

sprite_t *create_dog(sprite_t *dog)
{
    dog->texture = sfTexture_createFromFile("ressources/dog.jpg", NULL);
    dog->sprite = sfSprite_create();
    return (dog);
}

sprite_t *create_duck(sprite_t *duck)
{
    duck->texture = sfTexture_createFromFile("ressources/spritesheet.png", NULL);
    duck->sprite = sfSprite_create();
    duck->position.x = -200;
    srand(time(NULL));
    duck->position.y = (rand() % (700 - 100 + 1)) + 100;
    sfSprite_setPosition(duck->sprite, duck->position);
    return (duck);
}

background_t *create_background(background_t *background)
{
    background->texture = sfTexture_createFromFile("ressources/background.jpg", NULL);
    background->sprite = sfSprite_create();
    return (background);
}

void draw_sprite_back(background_t *background, sfRenderWindow *window)
{
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    sfRenderWindow_drawSprite(window, background->sprite, NULL);
}

void draw_sprite_animal(sprite_t *animal, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, animal->sprite, NULL);
}
