/*
** EPITECH PROJECT, 2018
** Alsaka | Bootstrap graphical programming | open_window
** File description:
** A function that open a window and don't close it
*/

#include "../include/my_hunter.h"

sfRenderWindow *create_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode mode;

    mode.width = width;
    mode.height = height;
    mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(mode, "Test Spray"
                                   , sfFullscreen, NULL);
    return (window);
}
