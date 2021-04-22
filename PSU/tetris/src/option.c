/*
** EPITECH PROJECT, 2019
** Tetris
** File description:
** Flag analyser
*/

#include <unistd.h>
#include <getopt.h>
#include "tetris.h"
#include "data.h"
#include "mlib.h"
#include <ncurses.h>

static const char *optstring = "L:l:r:t:d:q:p:wD";
static const struct option longopts[] = {
    {"help", 0, 0, 1},
    {"level", 1, 0, 'L'},
    {"key-left", 1, 0, 'l'},
    {"key-right", 1, 0, 'r'},
    {"key-turn", 1, 0, 't'},
    {"key-drop", 1, 0, 'd'},
    {"key-quit", 1, 0, 'q'},
    {"key-pause", 1, 0, 'p'},
    {"map-size", 1, 0, 2},
    {"without-next", 0, 0, 'w'},
    {"debug", 0, 0, 'D'},
    {0, 0, 0, 0}
};

static int key_load(void)
{
    if (mstrsame(" ", optarg) == 1)
        return (KEY_BACKSPACE);
    if (mstrsame("^EOA", optarg) == 1)
        return (KEY_UP);
    if (mstrsame("^EOB", optarg) == 1)
        return (KEY_DOWN);
    if (mstrsame("^EOC", optarg) == 1)
        return (KEY_RIGHT);
    if (mstrsame("^EOD", optarg) == 1)
        return (KEY_LEFT);
    return ((int)optarg[0]);
}

static void case_option1(data_t *data, int opt)
{
    switch (opt) {
    case 1:
        usage();
        break;
    case 'L':
        data->level = mgetnbr(optarg);
        break;
    case 'l':
        data->key_left = key_load();
        break;
    case 'r':
        data->key_right = key_load();
        break;
    }
}

static void case_option2(data_t *data, int opt)
{
    switch (opt) {
    case 't':
        data->key_turn = key_load();
        break;
    case 'd':
        data->key_drop = key_load();
        break;
    case 'q':
        data->key_quit = key_load();
        break;
    case 'p':
        data->key_pause = key_load();
        break;
    }
}

static void case_option3(data_t *data, int opt)
{
    switch (opt) {
    case 2:
        load_map_size(data, optarg);
        break;
    case 'W':
        data->without_next = true;
        break;
    case 'D':
        data->debug = true;
        break;
    }
}

void option(int ac, char **av, data_t *data)
{
    int opt = 0;

    while (1) {
        opt = getopt_long(ac, av, optstring, longopts, NULL);
        if (opt == -1)
            break;
        case_option1(data, opt);
        case_option2(data, opt);
        case_option3(data, opt);
    }
}
