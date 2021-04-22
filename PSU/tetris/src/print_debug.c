/*
** EPITECH PROJECT, 2019
** Tetris
** File description:
** Print debug
*/

#include "tetris.h"
#include "data.h"
#include "mlib.h"
#include <ncurses.h>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>

static void sputchar(int c)
{
    switch (c) {
    case KEY_DOWN:
        mputstr("^EOB");
        break;
    case KEY_UP:
        mputstr("^EOA");
        break;
    case KEY_LEFT:
        mputstr("^EOD");
        break;
    case KEY_RIGHT:
        mputstr("^EOC");
        break;
    case KEY_BACKSPACE:
        mputstr("(space)");
        break;
    default:
        mputchar((char)c);
    }
    mputchar('\n');
}

static void print_key(data_t data)
{
    mputstr("Key Left : ");
    sputchar(data.key_left);
    mputstr("Key Right : ");
    sputchar(data.key_right);
    mputstr("Key Turn : ");
    sputchar(data.key_turn);
    mputstr("Key Drop : ");
    sputchar(data.key_drop);
    mputstr("Key Quit : ");
    sputchar(data.key_quit);
    mputstr("Key Pause : ");
    sputchar(data.key_pause);
}

static void print_option(data_t data)
{
    mputstr("Next : ");
    if (data.without_next == false)
        mputstr("Yes\n");
    if (data.without_next == true)
        mputstr("No\n");
    mputstr("Level : ");
    mputnbr(data.level);
    mputchar('\n');
    mputstr("Size : ");
    mputnbr(data.map_row);
    mputchar('*');
    mputnbr(data.map_col);
    mputchar('\n');
}

static int non_block_read_mode(struct termios *caps)
{
    caps->c_lflag &= ~ICANON;
    caps->c_cc[VMIN] = 1;
    caps->c_cc[VTIME] = 0;
    if (tcsetattr(0, 0, caps) == -1)
        return (ERROR);
    return (SUCCESS);
}

void print_debug(data_t data)
{
    struct termios caps;
    char buf[1];

    mputstr("*** DEBUG MODE ***\n");
    print_key(data);
    print_option(data);
    print_tetriminos(data);
    mputstr("Press any key to start Tetris\n");
    tcgetattr(0, &caps);
    non_block_read_mode(&caps);
    read(0, buf, 1);
}
