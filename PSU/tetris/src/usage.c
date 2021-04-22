/*
** EPITECH PROJECT, 2019
** Tetris
** File description:
** Print the usage
*/

#include "mlib.h"

void usage(void)
{
    mputstr("Usage:\t./tetris [options]\n");
    mputstr("Options:\n");
    mputstr(" --help\t\t\tDisplay this help\n");
    mputstr(" -L --level={num}\tStart Tetris at level num (def: 1)\n");
    mputstr(" -l --key-left={K}\tMove the tetrimino LEFT using the K key");
    mputstr(" (def: left arrow)\n");
    mputstr(" -r --key-right={K}\tMove the tetrimino RIGHT using the K key");
    mputstr(" (def: right arrow)\n");
    mputstr(" -t --key-turn={K}\tTURN the tetrimino clockwise 90d using the K");
    mputstr(" key (def: top arrow)\n");
    mputstr(" -d --key-drop={K}\tDROP the tetrimino using the K key");
    mputstr(" (def: down arrow)\n");
    mputstr(" -q --key-quit={K}\tQUIT the game using the K key");
    mputstr(" (def: 'q' key)\n");
    mputstr(" -p --key-pause={K}\tPAUSE/RESTART the game using the K key");
    mputstr(" (def: space bar)\n");
    mputstr(" --map-size={row,col}\tSet the numbers of rows and columns of");
    mputstr(" the map (def: 20,10)\n");
    mputstr(" -w --without-next\tHide next tetrimino (def: false)\n");
    mputstr(" -D --debug\t\tDebug mode (def: false)\n");
}
