/*
** EPITECH PROJECT, 2018
** PSU my_sokoban | main
** File description:
** The main functions
*/

#include "include/sokoban.h"

void print_tab(char **tab, coord_t *coord)
{
    int linum = 0;

    clear();
    while (linum != coord->linum) {
        printw("%s\n", tab[linum]);
        linum++;
    }
}

char **reset_map(char **map, char **initial_map, coord_t *coord)
{
    int linum = 0;
    int cols = 0;

    while (linum != coord->linum) {
        if (cols == coord->cols) {
            cols = 0;
            linum++;
        }
        map[linum][cols] = initial_map[linum][cols];
        cols++;
    }
    coord = get_p(map, coord);
    return (map);
}

void sokoban_main(char **map, char *buffer, coord_t *coord)
{
    char **initial_map = get_tab(buffer, initial_map, coord);
    int nb_o = 0;

    check_nbr_xo(buffer);
    coord = check_p(buffer, map, coord);
    initscr();
    keypad(stdscr, true);
    while (1) {
        print_tab(map, coord);
        get_mvt_player(map, coord, initial_map);
        win_condition(map, initial_map, buffer, coord);
    }
}

int main(int ac, char **av)
{
    char *buffer = NULL;
    coord_t *coord = NULL;
    char **map = NULL;

    coord = malloc(sizeof(coord_t));
    if (ac != 2)
        return (84);
    else {
        if (av[1][0] == '-' && av[1][1] == 'h')
            display_help();
        else {
            buffer = fs_print_file(av[1], buffer);
            check_error(buffer);
            coord->linum = get_linum(buffer);
            coord->cols = get_cols_max(buffer);
            map = get_tab(buffer, map, coord);
            sokoban_main(map, buffer, coord);
        }
        return (0);
    }
}
