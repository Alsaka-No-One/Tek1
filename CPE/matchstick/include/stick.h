/*
** EPITECH PROJECT, 2019
** header
** File description:
** header
*/

#ifndef _STICK_H_
#define _STICK_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct coord_s {
    int line;
    int stick;
} coord_t;

char **fill_the_map(int);
void print_map(int, char **);
int game_loop(int, int, char **);
void display_usage(void);
int print_human_turn(void);
int print_number_remove(void);
int check_buffer(char *);
int remove_condition(int, coord_t *, char **, int);
void display_human_move(int, int);
void display_player_map(int, int, int, char **);
int check_stick_left(coord_t *, int, char **, int);
int ai(int, char **, int);
int check_buff(int, int);
int count_line_ai(int, char **, int);
int count_modulo(int, char **, int, int);
int replace_for_moment(int line, char **, int);
void display_ai_map(int, int, int, char**);
int count_for_ai(int, char **);

#endif
