/*
** EPITECH PROJECT, 2018
** MUL runner | character moove
** File description:
** The functions that make run the character
*/

#include "runner.h"

sfIntRect moove_the_rect(sfIntRect rect)
{
    rect.left += 85;
    if (rect.left == 510)
        rect.left = 0;
    return (rect);
}

void timer_for_run(float seconds, sfClock *clock, sprite_t *character)
{
    if (seconds > 0.1) {
        character->rect = moove_the_rect(character->rect);
        sfClock_restart(clock);
    }
}

sfVector2f jumping_character(sprite_t *character)
{
    static int jump = 0;
    sfClock *clock = sfClock_create();
    float seconds = 0;

    seconds = params_clock(seconds, clock);
    if (jump != 0) {
        if (jump < 300)
            character->position.y += 0.5;
        else if (jump == 300 || jump == 301 || seconds > 2)
            character->position.y = character->position.y;
        else
            character->position.y -= 0.5;
        jump -= 1;
        sfClock_restart(clock);
    }
    else if (sfKeyboard_isKeyPressed(sfKeySpace) == 1)
        jump = 600;
    return (character->position);
}

void running_charact(sfRenderWindow *window, game_t *g)
{
    g->character->position = jumping_character(g->character);
    sfSprite_setPosition(g->character->sprite, g->character->position);
    sfSprite_setTexture(g->character->sprite, g->character->texture, sfTrue);
    sfSprite_setTextureRect(g->character->sprite, g->character->rect);
    sfRenderWindow_drawSprite(window, g->character->sprite, NULL);
}
