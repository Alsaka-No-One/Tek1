/*
** EPITECH PROJECT, 2018
** Mul runner | header
** File description:
** The header
*/

#ifndef RUNNER_H_
#define RUNNER_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

typedef struct sprite_s {
    sfVector2f position;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f vector;
} sprite_t;

typedef struct game_s {
    sprite_t *character;
    sprite_t *foreground;
    sprite_t *parallax1;
    sprite_t *parallax2;
    sprite_t *parallax3;
    sprite_t *par;
    sprite_t *parallax5;
    sprite_t *par1;
    sprite_t *par5_2;
    sprite_t *par2_2;
    sprite_t *par3_2;
    sprite_t *for2;
    sprite_t *jb;
} game_t;

sfRenderWindow *create_window(unsigned int, unsigned int);
sprite_t *initialize_character(sprite_t *);
float params_clock(float, sfClock *);
void timer_for_run(float, sfClock *, sprite_t *);
void draw_all(sfRenderWindow *, sprite_t *, game_t *);
void draw_parallax(sfRenderWindow *, game_t *);
void draw_parallax2(sfRenderWindow *, game_t *);
void handle_event(sfRenderWindow *window, sprite_t *character);
sprite_t *initialize_foreground(sprite_t *);
sprite_t *initialize_parallax(sprite_t *, char const *);
sprite_t *initialize_infinite(sprite_t *, char const *filepath);
sprite_t *initialize_infinite2(sprite_t *, char const *filepath);
void infinite_management(sprite_t *, sprite_t *, sfVector2f);
sfVector2f jumping_character(sprite_t *);
void running_charact(sfRenderWindow *, game_t *);
game_t *initialize_struct(game_t *);
void draw_trees(sfRenderWindow *, game_t *);
char **fs_print_file(char const *);
char *my_strcpy(char *, char *);
int my_putstr(char const *);
void display_usage(void);
void create_map(sfRenderWindow *, char **);
char *my_put_nbr(int);

#endif
