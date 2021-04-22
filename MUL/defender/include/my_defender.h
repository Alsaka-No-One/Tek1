/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** my_defender
*/

#ifndef MY_DEFENDER_H_
#define MY_DEFENDER_H_

#include "my_defender2.h"

int main(int ac, char **av);
int menu(game_t *game);
int manage_event_menu(game_t *game);
void create_pause(game_t *game);
void manage_minions(game_t *game);
void manage_display_menu(game_t *game);
void handle_event(sfRenderWindow *window, sfEvent *event, button_t *button);
sfRectangleShape *init_button(sfRectangleShape *rect, sfVector2f position,
        sfVector2f size);
sfRenderWindow *create_window(unsigned int width, unsigned int height);
sfVector2f create_vector(float x, float y);
void upgrade_shop(game_t *game, sfVector2f pos, int i);
int menu_pause(game_t *game);
void check_upgrade(game_t *game, int x, int y, int i);
void upgrade_tower(game_t *game, int x, int y, int i);
bool button_is_clicked(button_t *button, sfVector2i click_position);
sfText *create_text(int pos_x, int pos_y, char *text);
sfText *set_color_text(sfText *text, sfFloatRect size,
        sfVector2f r_pos, sfVector2i mouse);
void initialize_draw_sprite(sprite_t *background,
        sfRenderWindow *window, char *fp);
void destroy_sprite(sprite_t *background, sprite_t *title);
cursor_t create_cursor(sfRenderWindow *window);
sfVector2f calcul_position_cursor(sfRenderWindow *window);
void check_type_of_tower(game_t *game, sfVector2f pos, char *fp, int i);
void calcul_score(game_t *game);
int analyse_arg(int ac, char **av);
int display_help(void);
void draw_bullet(game_t *game, int i);
void calcul_bullet(game_t *game, int i, int j);
void calcul_bullet_move(game_t *game, int i);

#endif
