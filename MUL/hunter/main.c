/*
** EPITECH PROJECT, 2018
** MUL my_hunter | main
** File description:
** The main function
*/

#include "include/my_hunter.h"

void hunter_main(sfRenderWindow *window, background_t *back, sprite_t *duck)
{
    sfEvent event;
    sfIntRect rect = initialize_rect(rect);
    sfClock *clock = sfClock_create();
    float seconds;
    sfVector2f offset;
    sfClock *clock_wings = sfClock_create();
    float seconds_wings;

    while (sfRenderWindow_isOpen(window)) {
        sfSprite_setTexture(duck->sprite, duck->texture, sfTrue);
        seconds = params_clock(seconds, clock);
        seconds_wings = params_clock(seconds_wings, clock_wings);
        if (seconds > 1.0 / 60.0) {
            duck = respawn_bird(duck);
            lost_check(duck, window);
            rect = draw_all(back, window, duck, rect);
            sfClock_restart(clock);
        }
        if (seconds_wings > 0.090) {
            rect = timer_for_wings(rect);
            sfClock_restart(clock_wings);
        }
        handle_event(window, event, duck);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
            sfRenderWindow_close(window);
    }
    sfRenderWindow_destroy(window);
    add_score(duck);
}

int main(int ac, char **av)
{
    int i = 0;
    sfRenderWindow *window;
    sprite_t *duck = malloc(sizeof(sprite_t));
    background_t *back = malloc(sizeof(background_t));

    if (ac == 1 ) {
        window = create_window(1920, 1080);
        duck = create_duck(duck);
        back = create_background(back);
        duck->nb = manage_speed();
        duck->lost_condition = 3;
        duck->score = 0;
        hunter_main(window, back, duck);
        return (0);
    }
    else if (av[1][0] == '-' && av[1][1] == 'h') {
        display_help();
        return (84);
    }
}
