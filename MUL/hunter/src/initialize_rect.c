/*
** EPITECH PROJECT, 2018
** MUL my_hunter | initialize rect
** File description:
** The function to initialize the rect
*/

#include "../include/my_hunter.h"

sfIntRect initialize_rect(sfIntRect rect)
{
    rect.top = 0;
    rect.left = 0;
    rect.width = 110;
    rect.height = 110;
    return (rect);
}

sfIntRect timer_for_wings(sfIntRect rect)
{
    rect.left = rect.left + 110;
    if (rect.left == 330)
        rect.left = 0;
    return (rect);
}
