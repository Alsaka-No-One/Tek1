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

int c_op(char *line)
{
    int u = 0;
    int p1 = 4;
    int p2 = 4;

    (cmp_c(line, 3, DIRECT_CHAR)) ? p1 = 2 : 0;
    (cmp_c(line, 3, REG_CHAR)) ? p1 = 1 : 0;
    u = get_c(line, u, SEPARATOR_CHAR) + 1;
    (cmp_c(line, u, DIRECT_CHAR)) ? p2 = 2 : 0;
    (cmp_c(line, u, REG_CHAR)) ? p2 = 1 : 0;
    return (3 + p1 + p2);
}

int c_st(char *line)
{
    int p = get_c(line, 0, SEPARATOR_CHAR) + 1;

    if (cmp_c(line, p, REG_CHAR))
        return (4);
    return (9);
}

int c_ld(char *line)
{
    if (cmp_c(line, 2, DIRECT_CHAR))
        return (7);
    return (7);
}

int cmd_len(char *line)
{
    int len = 0;

    (my_strcmp(line, "live ")) ? len = 5 : 0;
    (my_strcmp(line, "ld ")) ? len = c_ld(line) : 0;
    (my_strcmp(line, "st ")) ? len = c_st(line) : 0;
    (my_strcmp(line, "add ")) ? len = 5 : 0;
    (my_strcmp(line, "sub ")) ? len = 5 : 0;
    (my_strcmp(line, "and ")) ? len = c_op(line) : 0;
    (my_strcmp(line, "or ")) ? len = c_op(line) : 0;
    (my_strcmp(line, "xor ")) ? len = c_op(line) : 0;
    (my_strcmp(line, "zjmp ")) ? len = 3 : 0;
    (my_strcmp(line, "ldi ")) ? len = c_ldi(line) : 0;
    (my_strcmp(line, "sti ")) ? len = c_sti(line) : 0;
    (my_strcmp(line, "fork ")) ? len = 3 : 0;
    (my_strcmp(line, "lld ")) ? len = c_ld(line) : 0;
    (my_strcmp(line, "lldi ")) ? len = c_ldi(line) : 0;
    (my_strcmp(line, "lfork ")) ? len = 3 : 0;
    (my_strcmp(line, "aff ")) ? len = 3 : 0;
    return (len);
}

int *get_cmds_len(char **cmds, int max)
{
    int i = 0;
    int *len = malloc(sizeof(int) * (max + 1));
    char *mline;

    for (; cmds[i]; i++) {
        mline = my_line(cmds[i]);
        len[i] = cmd_len(mline);
        free(mline);
    }
    len[i] = -1;
    return (len);
}