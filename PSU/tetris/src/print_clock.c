/*
** EPITECH PROJECT, 2019
** Tetris
** File description:
** Print the clock
*/

#include <time.h>
#include <ncurses.h>

void print_clock(int x, int y)
{
    static clock_t elapsed_time = 0;
    clock_t time = clock();
    double clock;

    elapsed_time = time - elapsed_time;
    clock = (((double)elapsed_time) / CLOCKS_PER_SEC);
    mvprintw(y, x, "%.2lf\n", clock);
}
