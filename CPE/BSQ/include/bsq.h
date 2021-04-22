/*
** EPITECH PROJECT, 2018
** BSQ | bsq.h
** File description:
** just a header file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef __BSQ_H
#define __BSQ_H

int fs_open_file(char const *);
char *fs_print_file(char const *, char *);
int my_printf(char *, ...);
void error_open(void);
int my_strlen(char const *);
void fs_print_first_line(char const *);
char *pass_the_first_line(char *);
void my_putchar(char);
int my_getnbr(char const *);
char **string_to_tab(char *, int, int, char **);
int find_nb_cols(char *);
void print_tab(char **, int, int);
int **create_tab_rev_dem(char **, int, int, int **);
void print_int_tab(int **, int, int);
int **modif_tab_into_dem(int **, int, int);
int reverse_minesweeper(int **, int, int , int);
int get_the_biggest_number(int **, int, int);
int get_the_linum(int **, int, int , int);
int get_the_cols(int **, int, int , int);
char **draw_the_square(char **, int, int , int);
int my_putstr(char const *);

#endif
