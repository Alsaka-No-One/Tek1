/*
** EPITECH PROJECT, 2019
** PSU my_ls | header
** File description:
** header
*/

#ifndef LS_H_
#define LS_H_
#define WORD_SIZE 100

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int option(int, char **, int);
int disp(int, char **, int);
int my_putstr(char const *);
int my_printf(char *, ...);
int my_strlen(char const *);
int check_error(int, char **);
void check_option(int, char **, int);
void ls_d(int, char **);
int check_the_arg(int, char **);
void ls_l(void);
void disp_rights(mode_t );
void my_putchar(char c);
void color_the_name(char *, mode_t);
void recursivity(void);

#endif
