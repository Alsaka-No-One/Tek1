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

void w_sub(char *line, int out)
{
    int u = 3;
    char code = 0x05;
    int size = 54;

    write(out, &code, 1);
    write_nb(out, size, 1, 1);
    u = w_first(line, u, out, 0);
    u = w_next(line, u, out, 0);
    w_next(line, u, out, 0);
}

void w_add(char *line, int out)
{
    int u = 3;
    char code = 0x04;
    int size = 54;

    write(out, &code, 1);
    write_nb(out, size, 1, 1);
    u = w_first(line, u, out, 0);
    u = w_next(line, u, out, 0);
    w_next(line, u, out, 0);
}

void w_st(char *line, int out)
{
    int u = 2;
    char code = 0x03;
    int size = s_st(line);

    write(out, &code, 1);
    write_nb(out, size, 1, 1);
    u = w_first(line, u, out, 0);
    w_next(line, u, out, 0);
}

void w_ld(char *line, int out)
{
    int u = 2;
    char code = 0x02;
    int size = s_ld(line);

    write(out, &code, 1);
    write_nb(out, size, 1, 0);
    u = w_first(line, u, out, 0);
    w_next(line, u, out, 0);
}

void w_live(char *line, int out)
{
    char code = 0x01;
    int u = 4;
    int nb = nxtnbr(line, &u);
    write(out, &code, 1);
    write_nb(out, nb, 4, 0);
}