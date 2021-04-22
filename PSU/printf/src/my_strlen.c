/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** Task03
*/

#include "../include/function.h"

int my_strlen(char const *str)
{
    int turn;

    turn = 0;
    while (str[turn] != '\0'){
        turn = turn + 1;
    }
    return (turn);
}
