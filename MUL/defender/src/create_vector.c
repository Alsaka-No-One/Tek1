/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create_vector
*/

#include "my_defender.h"

sfVector2f create_vector(float x, float y)
{
    sfVector2f position;

    position.x = x;
    position.y = y;
    return (position);
}