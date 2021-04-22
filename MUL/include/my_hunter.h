/*
** EPITECH PROJECT, 2018
** MUL my_hunter | header file
** File description:
** The header of my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Audio.h>

#ifndef __MY_HUNTER_H
#define __MY_HUNTER_H

typedef struct sprite_s {
    sfVector2f position;
    sfTexture *texture;
    sfSprite *sprite;
    int nb;
    int lost_condition;
    int score;
} sprite_t;

typedef struct background_s {
    sfTexture *texture;
    sfSprite *sprite;
} background_t;

void display_help(void);
int my_printf(char *s, ...);
sfRenderWindow *create_window(unsigned int, unsigned int);
void handle_event(sfRenderWindow *, sfEvent, sprite_t *);
background_t *create_background(background_t *);
void draw_sprite_back(background_t *, sfRenderWindow *);
void draw_sprite_animal(sprite_t *, sfRenderWindow *);
sprite_t *create_duck(sprite_t *);
sprite_t *create_dog(sprite_t *);
sfIntRect initialize_rect(sfIntRect);
float params_clock(float, sfClock *);
sfIntRect moove_rect(sfIntRect);
sfIntRect draw_all(background_t *, sfRenderWindow *, sprite_t *, sfIntRect);
void moove_bird(sprite_t *, sfVector2f, int);
sfIntRect timer_for_wings(sfIntRect);
int manage_speed(void);
sprite_t *respawn_bird(sprite_t *);
void *lost_check(sprite_t *, sfRenderWindow *);
void add_score(sprite_t *);

#endif
