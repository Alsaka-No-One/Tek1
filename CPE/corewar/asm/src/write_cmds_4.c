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

int nxtnbr(char *str, int *u)
{
    int i = *u;
    long nb = 0;
    int len = 0;
    int signe = 1;

    for (;(((str[i] < '0') || (str[i] > '9')) && str[i] != '\0'
        && str[i] != '-' && str[i] != '+'); i++);
    for (; str[i] == '+' || str[i] == '-'; i++)
        signe = str[i];
    signe = (signe == '-') ? -1 : 1;
    for (;(str[i] && str[i] >= '0' && str[i] <= '9'); i++) {
        len++;
        nb = nb * 10 + (str[i] - 48);
    }
    *u = i;
    if (len == 0)
        return (-1);
    return (nb * signe);
}

int w_first(char *line, int u, int out, int t)
{
    int i = u;
    int nb = 0;

    for (; line[i] == ' '; i++);
    if (cmp_c(line, i, DIRECT_CHAR)) {
        nb = nxtnbr(line, &i);
        (t == 1 || t == 3) ? write_nb(out, nb, 2, 0) : 0;
        (t == 0 || t == 2) ? write_nb(out, nb, 4, 0) : 0;
    } else if (cmp_c(line, i, REG_CHAR)) {
        nb = nxtnbr(line, &i);
        write_nb(out, nb, 1, 0);
    } else {
        nb = nxtnbr(line, &i);
        (t == 2 || t == 3) ? write_nb(out, nb, 2, 0) : 0;
        (t == 1 || t == 0) ? write_nb(out, nb, 4, 0) : 0;
    }
    return (i);
}

int w_next(char *line, int u, int out, int t)
{
    int i = u;
    int nb = 0;

    i = get_c(line, i, SEPARATOR_CHAR) + 1;
    if (cmp_c(line, i, DIRECT_CHAR)) {
        nb = nxtnbr(line, &i);
        (t == 1 || t == 3) ? write_nb(out, nb, 2, 0) : 0;
        (t == 0 || t == 2) ? write_nb(out, nb, 4, 0) : 0;
    } else if (cmp_c(line, i, REG_CHAR)) {
        nb = nxtnbr(line, &i);
        write_nb(out, nb, 1, 0);
    } else {
        nb = nxtnbr(line, &i);
        (t == 2 || t == 3) ? write_nb(out, nb, 2, 0) : 0;
        (t == 1 || t == 0) ? write_nb(out, nb, 4, 0) : 0;
    }
    return (i);
}

void w_aff(char *line, int out)
{
    int u = 3;
    char code = 0x10;
    int size = 40;
    int nb = nxtnbr(line, &u);

    write(out, &code, 1);
    write_nb(out, size, 1, 1);
    write_nb(out, nb, 1, 0);
}

void write_cmds(char *line, int out)
{
    (my_strcmp(line, "live ")) ? w_live(line, out) : 0;
    (my_strcmp(line, "ld ")) ? w_ld(line, out) : 0;
    (my_strcmp(line, "st ")) ? w_st(line, out) : 0;
    (my_strcmp(line, "add ")) ? w_add(line, out) : 0;
    (my_strcmp(line, "sub ")) ? w_sub(line, out) : 0;
    (my_strcmp(line, "and ")) ? w_and(line, out) : 0;
    (my_strcmp(line, "or ")) ? w_or(line, out) : 0;
    (my_strcmp(line, "xor ")) ? w_xor(line, out) : 0;
    (my_strcmp(line, "zjmp ")) ? w_zjmp(line, out) : 0;
    (my_strcmp(line, "ldi ")) ? w_ldi(line, out) : 0;
    (my_strcmp(line, "sti ")) ? w_sti(line, out) : 0;
    (my_strcmp(line, "fork ")) ? w_fork(line, out) : 0;
    (my_strcmp(line, "lld ")) ? w_lld(line, out) : 0;
    (my_strcmp(line, "lldi ")) ? w_lldi(line, out) : 0;
    (my_strcmp(line, "lfork ")) ? w_lfork(line, out) : 0;
    (my_strcmp(line, "aff ")) ? w_aff(line, out) : 0;
}