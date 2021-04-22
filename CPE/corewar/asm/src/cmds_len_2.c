/*
** EPITECH PROJECT, 2019
** label
** File description:
** cmds_len
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "op.h"
#include "asm.h"

int s_op(char *line)
{
    int u = 0;
    int p1 = 4;
    int p2 = 4;

    (cmp_c(line, 3, DIRECT_CHAR)) ? p1 = 2 : 0;
    (cmp_c(line, 3, REG_CHAR)) ? p1 = 1 : 0;
    u = get_c(line, u, SEPARATOR_CHAR) + 1;
    (cmp_c(line, u, DIRECT_CHAR)) ? p2 = 2 : 0;
    (cmp_c(line, u, REG_CHAR)) ? p2 = 1 : 0;
    return (convert_op(p1, p2));
}

int s_st(char *line)
{
    int p = get_c(line, 0, SEPARATOR_CHAR) + 1;

    if (cmp_c(line, p, REG_CHAR))
        return (50);
    return (70);
}

int s_ld(char *line)
{
    if (cmp_c(line, 3, DIRECT_CHAR))
        return (144);
    return (208);
}

int c_sti(char *line)
{
    int u = get_c(line, 0, SEPARATOR_CHAR) + 1;
    int p1 = 4;
    int p2 = 4;

    (cmp_c(line, u, DIRECT_CHAR)) ? p1 = 2 : 0;
    (cmp_c(line, u, REG_CHAR)) ? p1 = 1 : 0;
    u = get_c(line, u, SEPARATOR_CHAR) + 1;
    (cmp_c(line, u, DIRECT_CHAR)) ? p2 = 2 : 0;
    (cmp_c(line, u, REG_CHAR)) ? p2 = 1 : 0;
    return (3 + p1 + p2);
}

int c_ldi(char *line)
{
    int u = 3;
    int p1 = 4;
    int p2 = 4;

    u = get_c(line, 0, SEPARATOR_CHAR) + 1;
    (cmp_c(line, u, DIRECT_CHAR)) ? p1 = 2 : 0;
    (cmp_c(line, u, REG_CHAR)) ? p1 = 1 : 0;
    u = get_c(line, u, SEPARATOR_CHAR) + 1;
    (cmp_c(line, u, DIRECT_CHAR)) ? p2 = 2 : 0;
    (cmp_c(line, u, REG_CHAR)) ? p2 = 1 : 0;
    return (3 + p1 + p2);
}