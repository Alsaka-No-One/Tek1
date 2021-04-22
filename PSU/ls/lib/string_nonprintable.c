/*
** EPITECH PROJECT, 2018
** PSU my_printf | %S
** File description:
** A function that display value of non printable character in ascii
*/

#include "include/function.h"

void my_putstr_no_printable(char *str)
{
    int i = 0;
    int ascii_value;

    while (str[i] != '\0') {
        if (str[i] >= 32 && str[i] < 127)
            my_putchar(str[i]);
        else if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            ascii_value = str[i];
            convert_to_octal2(ascii_value);
        }
        i++;
    }
}
