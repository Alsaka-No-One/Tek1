/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** analyse_arg
*/

#include "my_defender.h"

int analyse_arg(int ac, char **av)
{
    game_t game;
    int status = 0;

    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0'))
        return (display_help());
    if (ac != 1)
        return (error_arg());
    game.window = create_window(1920, 1080);
    if (menu(&game) == 0) {
        sfRenderWindow_destroy(game.window);
        return (0);
    } else {
        status = my_defender(&game);
        sfRenderWindow_destroy(game.window);
        return (status);
    }
}

int display_help(void)
{
    write(1, "[USAGE]:\n\t./my_defender\n\n", 25);
    write(1, "[DESCRIPTION]:\n\t", 16);
    write(1, "This program is a tower defense game.\n\t", 39);
    write(1, "You have to put some towers in order to defend a village", 57);
    write(1, " from the monsters that will spawn", 35);
    write(1, " on the left side of your screen.\n", 34);
    write(1, "\n[TIPS]:\n\t", 10);
    write(1, "You can upgrade your differents towers if you", 45);
    write(1, " click on it.\n", 14);
    write(1, "[TOWER]\n\ttower 1: basic range, low damages ", 43);
    write(1, "and basic attack speed\n\ttower 2: low range, low ", 47);
    write(1, "damages and high attack speed\n\t", 31);
    write(1, "tower 3: very high range, high damages and ", 43);
    write(1, "very low speed\n\ttower 4: over cheat\n", 36);
    return (0);
}

int error_arg(void)
{
    write(1, "Try '-h' for more information\n", 30);
    return (84);
}
