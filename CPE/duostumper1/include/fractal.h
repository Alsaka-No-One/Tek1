/*
** EPITECH PROJECT, 2019
** fractal
** File description:
** including file
*/

#ifndef __FRACTAL_H_
#define __FRACTAL_H_

int check_middle_charact(char **av);
int compteur_charact(char **av);
int fractal(char **av);
void my_putchar(char c);
int my_getnbr(char const *str);
int my_strlen(char const *str);
int size_error(char **av);
int charact_error(char **av);
int check_error_return(char **av);
int check_error_return(char **av);
char *replace_str(char *str, char old, char new);
int draw_dractal(char **av, int i);
int my_putstr(char const *str);

#endif
