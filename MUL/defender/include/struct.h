/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** header
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "my_defender.h"

typedef struct button_s
{
    sfRectangleShape *rect;
    sfTexture *texture;
    sfRectangleShape *quit_rect;
    sfTexture *texture_quit;
    sfRectangleShape *tuto_rect;
    sfTexture *texture_tuto;
} button_t;

typedef struct sprite_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
} sprite_t;

typedef struct cursor_s
{
    sprite_t view;
    int status;
    sprite_t d_and_d;
} cursor_t;

typedef struct menu_s
{
    button_t button;
    sfText *text;
    sfText *quit_text;
    sfText *tuto_text;
    sprite_t background;
    sprite_t title;
    sfMusic *music;
} menu_t;

typedef struct rect_s
{
    sfRectangleShape *tower1;
    sfRectangleShape *tower2;
    sfRectangleShape *tower3;
    sfRectangleShape *tower4;
} rect_t;

typedef struct bullet_s
{
    sprite_t view;
    int nb_m;
    int status;
} bullet_t;

typedef struct tower_s
{
    sprite_t view;
    rect_t rect;
    bullet_t bullet;
    char type;
    int shoot;
    sfClock *clock;
    int vitesse;
    sfMusic *hit;
    sfVector2f range;
    sfVector2f range_sd;
} tower_t;

typedef struct shop_s
{
    int po_nb;
    sfText *cost;
    sfText *po;
    sprite_t view;
    int status;
} shop_t;

typedef struct charact_s
{
    sprite_t minion;
    sfClock *anim;
    sfIntRect rect;
    sfRectangleShape *sh_life;
    sfVector2f rc_life;
    int life;
    int type;
    sfMusic *death;
} charact_t;

typedef struct in_g_s
{
    sprite_t backg;
    tower_t *tower;
    int score_nb;
    int life_nb;
    sfText *score;
    sfClock *score_c;
    sfText *life;
    charact_t *charact;
    sfMusic *music;
    sfMusic *place_td;
    sfMusic *up_td;
    shop_t shop;
    sfClock *spawn;
    int nb_minions;
} in_g_t;

typedef struct button_pause_s
{
    sfRectangleShape *resume;
    sfTexture *resume_text;
    sfRectangleShape *quit;
    sfTexture *quit_text;
    sfRectangleShape *back;
    sfTexture *back_text;
} button_pause_t;

typedef struct pause_s
{
    button_pause_t button;
    sprite_t bg;
    sfText *resume;
    sfText *quit;
    sfText *back;
} pause_t;

typedef struct game_s
{
    pause_t pause;
    in_g_t ig;
    sfRenderWindow *window;
    sfEvent event;
    menu_t menu;
    cursor_t cursor;
} game_t;

#endif
