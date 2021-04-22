/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** destroy2
*/

#include "my_defender.h"

void destroy2(game_t *game)
{
    sfRectangleShape_destroy(game->ig.tower->rect.tower1);
    sfRectangleShape_destroy(game->ig.tower->rect.tower2);
    sfRectangleShape_destroy(game->ig.tower->rect.tower3);
    sfRectangleShape_destroy(game->ig.tower->rect.tower4);
}