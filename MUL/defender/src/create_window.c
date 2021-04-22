/*
** EPITECH PROJECT, 2018
** Alsaka | Bootstrap graphical programming | open_window
** File description:
** A function that open a window and don't close it
*/

#include "my_defender.h"

sfRenderWindow *create_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode mode;

    mode.width = width;
    mode.height = height;
    mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(mode, "My Defender", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}
