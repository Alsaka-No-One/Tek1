/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create_rect
*/

#include "my_defender.h"

sfIntRect create_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}