/*
** EPITECH PROJECT, 2018
** MUL runner | manage_event
** File description:
** The functions to manage te differents event
*/

#include "runner.h"

void handle_event(sfRenderWindow *window, sprite_t * character)
{
    (void)character;
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
        sfRenderWindow_close(window);
}
