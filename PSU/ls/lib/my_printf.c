/*
** EPITECH PROJECT, 2018
** Alsaka | PSU | my_printf
** File description:
** recode printf
*/

#include "include/function.h"

void find_flag2(char *s, int i, va_list list)
{
    switch (s[i]) {
    case 'u':
        my_put_nbr_long(va_arg(list, long));
        break;
    case 'x':
        convert_hexa_low(va_arg(list, int));
        break;
    case 'X':
        convert_hexa_maj(va_arg(list, int));
        break;
    case 'b':
        convert_binary(va_arg(list, int));
        break;
    case 'o':
        convert_to_octal(va_arg(list, int));
        break;
    case 'S':
        my_putstr_no_printable(va_arg(list, char *));
        break;
    }
}

void find_flag(char *s, int i, va_list list)
{
    switch (s[i]) {
    case 'c':
        my_putchar(va_arg(list, int));
        break;
    case 's':
        my_putstr(va_arg(list, char *));
        break;
    case 'd':
        my_put_nbr(va_arg(list, int));
        break;
    case 'i':
        my_put_nbr(va_arg(list, int));
        break;
    }
    find_flag2(s, i, list);
    if (s[i] == 'l' && s[i + 1] == 'd')
        my_put_nbr_long(va_arg(list, long));
}

int my_printf(char *s, ...)
{
    va_list list;
    int i = 0;

    va_start(list, s);
    while (s[i] != '\0') {
        if (s[i] == '%') {
            i++;
            find_flag(s, i, list);
        }
        else
            my_putchar(s[i]);
        i++;
    }
    va_end(list);
    return (0);
}
