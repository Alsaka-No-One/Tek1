/*
** EPITECH PROJECT, 2018
** PSU my_sokoban | header
** File description:
** Just the header file
*/


#ifndef __SOKOBAN_H
#define __SOKOBAN_H

#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct coord_s {
    int linum;
    int cols;
    int p_linum;
    int p_cols;
} coord_t;

void display_help(void);
int my_strlen(char const *);
int my_putstr(char const *str);
char *fs_print_file(char const *filepath, char *buffer);
void error_open(void);
void check_error(char *);
int get_linum(char *);
int get_cols_max(char *);
char **get_tab(char *, char **, coord_t *);
coord_t *check_p(char *, char **, coord_t *);
coord_t *get_p(char **, coord_t *);
void moove_down(char **, coord_t *);
void moove_up(char **, coord_t *);
void moove_left(char **, coord_t *);
void moove_right(char **, coord_t *);
void get_mvt_player(char **, coord_t *, char **);
void check_box_up(char **, coord_t *, char);
void check_box_down(char **, coord_t *, char);
void check_box_left(char **, coord_t *, char);
void check_box_right(char **, coord_t *, char);
char **reset_map(char **, char **, coord_t *);
void check_nbr_xo(char *);
void check_nbr_p(char *);
void win_condition(char **, char **, char *, coord_t *);

#endif
