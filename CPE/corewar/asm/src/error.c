/*
** EPITECH PROJECT, 2019
** label
** File description:
** analyse
*/

#include <stdlib.h>
#include "asm.h"

void choose_error2(int c)
{
    if (c == 9)
        my_puts(2, ": The program name is too long.\n");
    if (c == 10)
        my_puts(2, ": Multiple definition of the same label.\n");
    if (c == 11)
        my_puts(2, ": Invalid register number.\n");
    if (c == 12)
        my_puts(2, ": The comment is too long.\n");
}

void choose_error1(int c)
{
    if (c == 1)
        my_puts(2, ": Invalid instruction.\n");
    if (c == 2)
        my_puts(2, ": The argument given to the instruction is invalid.\n");
    if (c == 3)
        my_puts(2, ": The comment must be just after the name.\n");
    if (c == 4)
        my_puts(2, ": The name can only be defined once.\n");
    if (c == 5)
        my_puts(2, ": Warning: No comment specified.\n");
    if (c == 6)
        my_puts(2, ": The comment can only be defined once.\n");
    if (c == 7)
        my_puts(2, ": Undefined label.\n");
    if (c == 8)
        my_puts(2, ": Multiple definition of the same label.\n");
}

int replace_line(int i)
{

    for (int u = 0; TOTAL_FILE[u]; u++) {
        if (cmp_l(TOTAL_CMDS[i], TOTAL_FILE[u]))
            return (u + 1);
    }
    return (0);
}

void error(char *file, int i, int c, int p)
{
    my_puts(2, "asm, ");
    my_puts(2, file);
    my_puts(2, ", line ");
    if (p == 1)
        my_puts(2, my_itoa(replace_line(i)));
    else
        my_puts(2, my_itoa(i + 1));
    choose_error1(c);
    choose_error2(c);
    exit(84);
}

void error_n(char *file, int i)
{
    my_puts(2, "asm, ");
    my_puts(2, file);
    my_puts(2, ", line ");
    my_puts(2, my_itoa(i + 1));
    my_puts(2, ": No name specified.\n");
}