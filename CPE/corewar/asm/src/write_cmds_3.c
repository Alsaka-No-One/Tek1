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

void w_lfork(char *line, int out)
{
    int u = 5;
    char code = 0x0f;
    int nb = nxtnbr(line, &u);

    write(out, &code, 1);
    write_nb(out, nb, 2, 0);
}

void w_lldi(char *line, int out)
{
    int u = 4;
    char code = 0x0e;
    int size = s_ldi(line);
    int nb1 = nxtnbr(line, &u);

    write(out, &code, 1);
    write_nb(out, size, 1, 1);
    write_nb(out, nb1, 1, 1);
    u = w_next(line, u, out, 1);
    w_next(line, u, out, 1);
}

void w_lld(char *line, int out)
{
    int u = 4;
    char code = 0x0d;
    int size = s_ld(line);

    write(out, &code, 1);
    write_nb(out, size, 1, 0);
    u = w_first(line, u, out, 0);
    w_next(line, u, out, 0);
}

void w_fork(char *line, int out)
{
    int u = 4;
    char code = 0x0c;
    int nb = nxtnbr(line, &u);

    write(out, &code, 1);
    write_nb(out, nb, 2, 0);
}

void w_sti(char *line, int out)
{
    int u = 3;
    char code = 0x0b;
    int size = s_sti(line);
    int nb1 = nxtnbr(line, &u);

    write(out, &code, 1);
    write_nb(out, size, 1, 1);
    write_nb(out, nb1, 1, 1);
    u = w_next(line, u, out, 1);
    w_next(line, u, out, 1);
}