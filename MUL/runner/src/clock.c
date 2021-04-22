/*
** EPITECH PROJECT, 2018
** MUL runner | clock
** File description:
** The clock
*/

#include "runner.h"

float params_clock(float seconds, sfClock *clock)
{
    sfTime time;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    return (seconds);
}
