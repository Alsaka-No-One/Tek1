/*
** EPITECH PROJECT, 2019
** label
** File description:
** write_cmds
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "op.h"
#include "asm.h"

void w_ldi(char *line, int out)
{
    int u = 3;
    char code = 0x0a;
    int size = s_ldi(line);
    int nb1 = nxtnbr(line, &u);

    write(out, &code, 1);
    write_nb(out, size, 1, 1);
    write_nb(out, nb1, 1, 1);
    u = w_next(line, u, out, 1);
    w_next(line, u, out, 1);
}

void w_zjmp(char *line, int out)
{
    char code = 0x09;
    int u = 4;
    int nb = nxtnbr(line, &u);

    write(out, &code, 1);
    write_nb(out, nb, 2, 0);
}

void w_xor(char *line, int out)
{
    int u = 3;
    char code = 0x08;
    int size = s_op(line);

    write(out, &code, 1);
    write_nb(out, size, 1, 0);
    u = w_first(line, u, out, 2);
    u = w_next(line, u, out, 2);
    w_next(line, u, out, 2);
}

void w_or(char *line, int out)
{
    int u = 3;
    char code = 0x07;
    int size = s_op(line);

    write(out, &code, 1);
    write_nb(out, size, 1, 0);
    u = w_first(line, u, out, 2);
    u = w_next(line, u, out, 2);
    w_next(line, u, out, 2);
}

void w_and(char *line, int out)
{
    int u = 3;
    char code = 0x06;
    int size = s_op(line);

    write(out, &code, 1);
    write_nb(out, size, 1, 0);
    u = w_first(line, u, out, 2);
    u = w_next(line, u, out, 2);
    w_next(line, u, out, 2);
}