/*
** EPITECH PROJECT, 2018
** MUL my_hunter | adding score
** File description:
** The function to add the end game
*/

#include "include/my_hunter.h"

void add_score(sprite_t *duck)
{
    if (duck->score == 0) {
        my_printf("\t\tGAME OVER!\n");
        my_printf("Thx for playing!\n");
        my_printf("your score: O \n");
    }
    else {
        my_printf("\t\tGAME OVER!\n");
        my_printf("Thx for playing!\n");
        my_printf("your score: %d\n", duck->score);
    }
}
