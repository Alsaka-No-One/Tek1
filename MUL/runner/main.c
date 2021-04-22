/*
** EPITECH PROJECT, 2018
** MUL my_runner | main
** File description:
** The main function
*/

#include "runner.h"

void draw_score(sfRenderWindow *window)
{
    sfFont *font = NULL;
    static int score = 0;
    sfText *text = NULL;
    sfVector2f position;

    position.x = 27;
    position.y = 18;
    font = sfFont_createFromFile("ressources/font.ttf");
    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setString(text, my_put_nbr(score));
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(window, text, NULL);
    score += 10;
}
void runner_main(char **map, sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    float seconds;
    sfClock *running_clock = sfClock_create();
    float running_seconds;
    game_t *game = NULL;
    sfMusic *music = NULL;

    music = sfMusic_createFromFile("ressources/melody_new.ogg");
    game = malloc(sizeof(game_t) * 2);
    game = initialize_struct(game);
    sfMusic_play(music);
    while (sfRenderWindow_isOpen(window)) {
        seconds = params_clock(seconds, clock);
        running_seconds = params_clock(running_seconds, running_clock);
        handle_event(window, game->character);
        if (seconds > 1.0 / 60.0) {
            draw_parallax(window, game);
            draw_parallax2(window, game);
            draw_all(window, game->foreground, game);
            sfClock_restart(clock);
        }
        create_map(window, map);
        running_charact(window, game);
        if (seconds > 1.0 / 60.0) {
            draw_trees(window, game);
            sfRenderWindow_display(window);
            sfRenderWindow_clear(window, sfBlack);
            sfClock_restart(clock);
        }
        draw_score(window);
        timer_for_run(running_seconds, running_clock, game->character);
    }
    sfRenderWindow_destroy(window);
    sfMusic_destroy(music);
}

int main(int argc, char **argv)
{
    sfRenderWindow *window = NULL;
    char **map = NULL;

    if (argc != 2) {
        display_usage();
        return (84);
    }
    else {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            display_usage();
            return (0);
        }
        if ((map = fs_print_file(argv[1])) == NULL)
            return (84);
        window = create_window(1920, 1080);
        //create_map(window, map);
        runner_main(map, window);
        return (0);
    }
}
