/*
** EPITECH PROJECT, 2019
** heazder
** File description:
** header
*/

#ifndef SHELL_H_
#define SHELL_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int str_comp(char *, char *);
char **print_env(char **, char **arg);
char **set_env(char **, char **arg);
char **remalloc(char **);
char **string_to_arg(char *);
int my_exit(char **);
char **destroy_arg(char **);

#endif
