/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** score
*/

#include "my_defender.h"

void calcul_score(game_t *game)
{
    float seconds;

    seconds = params_clock(seconds, game->ig.score_c);
    if (seconds > 9.0 / 60.0) {
        game->ig.score_nb++;
        sfClock_restart(game->ig.score_c);
    }
}