/*
** EPITECH PROJECT, 2018
** Alsaka | PSU | header
** File description:
** header
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#ifndef __PRINT_H
#define __PRINT_H

void my_putchar(char);
int my_putstr(char const *);
int my_put_nbr(int);
int my_printf(char *, ...);
char *my_revstr(char *);
int my_strlen(char const *);
char *convert_hexa_maj(int);
char *convert_hexa_low(int);
char *convert_to_octal(int);
char *convert_binary(int);
char *convert_to_octal2(int);
void my_putstr_no_printable(char *);
char *my_put_nbr_long(long);

#endif
