/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** my_defender2
*/

#ifndef MY_DEFENDER2_H_
#define MY_DEFENDER2_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "struct.h"
#include "my_defender.h"

void create_menu(game_t *game);
void display_game(game_t *game);
int manage_event_game(game_t *game);
void select_tower(game_t *game, sfVector2f pos, int i, char *fp);
void place_tower(game_t *game, int x, int y, int i);
int error_arg(void);
void display_cursor(game_t *game);
void display_shop(game_t *game);
void create_game_two(game_t *game);
void manage_upgrade(game_t *game);
int my_defender(game_t *game);
void select_drag_and_drop(game_t *game, int x, int status, char *fp);
void manage_drag_and_drop(game_t *game);
int create_game(game_t *game);
char *create_str_of_nb(int nb, int size);
char *nbr_to_str(int nb);
void destroy_all_menu(game_t *game);
void destroy_menu(game_t *game);
void tower_rect(game_t *game);
void display_tower_rect(game_t *game);
void set_color_rect(game_t *game);
int manage_event_menu_pause_tree(game_t *game);
void display_menu_pause_two(game_t *game);
void display_menu_pause(game_t *game);
int manage_event_menu_pause(game_t *game, int *status);
int manage_event_menu_pause_two(game_t *game, int *status);
sfIntRect create_rect(int top, int left, int width, int height);
void display_text(game_t *game);
void initialize_charact(charact_t *charact, sfRenderWindow *window);
void initialize_charact_two(charact_t *charact, sfRenderWindow *window);
void path_minion(game_t *game, int i);
float params_clock(float seconds, sfClock *clock);
void shoot_tower(game_t *game, int i);
void minions_death(game_t *game, int j, int *k, int i);
void int_to_char(int nb, sfText *text, game_t *game);
void tower_type_four(game_t *game, sfVector2f pos, int i, char *fp);
void tower_type_tree(game_t *game, sfVector2f pos, int i, char *fp);
void tower_type_two(game_t *game, sfVector2f pos, int i, char *fp);
void tower_type_one(game_t *game, sfVector2f pos, int i, char *fp);
void up_tower_type_four(game_t *game, sfVector2f pos, char *fp, int i);
void up_tower_type_tree(game_t *game, sfVector2f pos, char *fp, int i);
void up_tower_type_two(game_t *game, sfVector2f pos, char *fp, int i);
void up_tower_type_one(game_t *game, sfVector2f pos, char *fp, int i);
void destroy_window_mouse(game_t *game);
void destroy_in_game(game_t *game, int status);
void destroy_loop(game_t *game);
void destroy_pause(game_t *game);
sfRectangleShape *init_button_text(sfRectangleShape *rect,
        sfVector2f position, sfVector2f size, sfTexture *texture);
void destroy2(game_t *game);
void hit_base(game_t *game, int i);
int display_tuto(game_t *game);
sfRectangleShape *init_button_life(sfRectangleShape *rect,
        sfVector2f position, sfVector2f size);
void life_rect(game_t *game, int i);
void position_life(game_t *game, int i);
void size_life(game_t *game, int j);

#endif
