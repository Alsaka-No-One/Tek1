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

int cmp_c(char const *line, int d, char c)
{
    int i = d;

    for (; line[i] && line[i] == ' '; i++);
    if (line[i] == c)
        return (i);
    return (0);
}

int get_c(char const *line, int start, char c)
{
    int i = start;

    for (; line[i] && line[i] != c; i++);
    if (line[i])
        return (i);
    return (0);
}

int s_sti(char *line)
{
    int u = get_c(line, 0, SEPARATOR_CHAR) + 1;
    int p = 74;

    (cmp_c(line, u, DIRECT_CHAR)) ? p -= 10 : 0;
    (cmp_c(line, u, REG_CHAR)) ? p -= 20 : 0;
    u = get_c(line, u, SEPARATOR_CHAR) + 1;
    (cmp_c(line, u, DIRECT_CHAR)) ? p += 4 : 0;
    return (p);
}

int s_ldi(char *line)
{
    int u = 3;
    int p = 74;

    u = get_c(line, u, SEPARATOR_CHAR) + 1;
    (cmp_c(line, u, DIRECT_CHAR)) ? p -= 10 : 0;
    (cmp_c(line, u, REG_CHAR)) ? p -= 20 : 0;
    u = get_c(line, u, SEPARATOR_CHAR) + 1;
    (cmp_c(line, u, DIRECT_CHAR)) ? p += 4 : 0;
    return (p);
}

int convert_op(int p1, int p2)
{
    int nb = 0;

    (p1 == 1 && p2 == 1) ? nb = 83 : 0;
    (p1 == 4 && p2 == 1) ? nb = 212 : 0;
    (p1 == 2 && p2 == 1) ? nb = 148 : 0;
    (p1 == 1 && p2 == 4) ? nb = 116 : 0;
    (p1 == 4 && p2 == 4) ? nb = 244 : 0;
    (p1 == 2 && p2 == 4) ? nb = 180 : 0;
    (p1 == 1 && p2 == 2) ? nb = 100 : 0;
    (p1 == 4 && p2 == 2) ? nb = 228 : 0;
    (p1 == 2 && p2 == 2) ? nb = 164 : 0;
    return (nb);
}