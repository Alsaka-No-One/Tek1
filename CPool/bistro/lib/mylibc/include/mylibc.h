/*
** EPITECH PROJECT, 2018
** Kaminari - MyLibC | My Lib C
** File description:
** Header file that contains function prototypes
*/

#pragma once

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

void my_putchar(char c);
void my_putstr(char *str);
int my_strlen(char *str);
int my_put_nbr(int nb);
int my_getnbr(char const *str);
char *my_strcat(char *dest, char *src);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strdup(char *src);
char *my_revstr(char *str);
bool my_isneg(int n);
