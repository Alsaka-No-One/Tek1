/*
** EPITECH PROJECT, 2018
** MUL my_hunter | clock
** File description:
** The clock
*/

#include "../include/my_hunter.h"

float params_clock(float seconds, sfClock *clock)
{
    sfTime time;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    return (seconds);
}
