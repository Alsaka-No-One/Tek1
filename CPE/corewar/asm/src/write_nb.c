/*
** EPITECH PROJECT, 2019
** label
** File description:
** write_nb
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "op.h"
#include "asm.h"

void fill_with_zero(int out, int ct_line, int type)
{
    char zero = 0x00;
    int size;

    if (type == 1)
        size = PROG_NAME_LENGTH - ct_line - 4;
    if (type == 2)
        size = COMMENT_LENGTH - ct_line + 4;
    for (; size > 0; size--)
        write(out, &zero, 1);
}

int chartoint(int c)
{
    char hex[] = "aAbBcCdDeEfF";
    int i;
    int result = 0;

    for (i = 0; result == 0 && hex[i] != '\0'; i++)
        if (hex[i] == c)
            result = 10 + (i / 2);
    return (result);
}

int htoi(const char *s)
{
    int r = 0;
    int i = 0;
    int p = 1;
    int t;

    while (p && s[i] != '\0') {
        r = r * 16;
        if (s[i] >= '0' && s[i] <= '9')
            r = r + (s[i] - '0');
        else {
            t = chartoint(s[i]);
            if (t == 0)
                p = 0;
            else
                r = r + t;
        }
        ++i;
    }
    return (r);
}

void choose_size(int out, char *chars, int size)
{
    if (size == 1)
        write(out, &chars[0], 1);
    if (size == 2) {
        write(out, &chars[1], 1);
        write(out, &chars[0], 1);
    }
    if (size == 3) {
        write(out, &chars[2], 1);
        write(out, &chars[1], 1);
        write(out, &chars[0], 1);
    }
    if (size == 4) {
        write(out, &chars[3], 1);
        write(out, &chars[2], 1);
        write(out, &chars[1], 1);
        write(out, &chars[0], 1);
    }
}

void write_nb(int out, int nb, int size, int v)
{
    char *toa = my_itoa(nb);
    int nnb = htoi(toa);
    char *chars = (char *) &nnb;
    int invert = 65536 - nb;

    if (nb < 0)
        chars = (char *) &invert;
    if (v == 0)
        chars = (char *) &nb;
    free(toa);
    choose_size(out, chars, size);
}