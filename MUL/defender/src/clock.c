/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** clock
*/

#include "my_defender.h"

float params_clock(float seconds, sfClock *clock)
{
    sfTime time;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    return (seconds);
}