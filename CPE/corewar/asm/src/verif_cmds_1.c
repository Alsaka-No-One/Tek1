/*
** EPITECH PROJECT, 2019
** asm
** File description:
** verif_cmds
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "op.h"
#include "asm.h"

void v_st(char *line, int i, char *filename)
{
    int u = 2;

    verif_reg(line, u, i, filename);
    u = get_c(line, u, SEPARATOR_CHAR) + 1;
    verif_inr(line, u, i, filename);
}

void v_ld(char *line, int i, char *filename)
{
    int u = 3;

    verif_dni(line, u, i, filename);
    u = get_c(line, u, SEPARATOR_CHAR) + 1;
    verif_reg(line, u, i, filename);
}

void v_live(char *line, int i, char *filename)
{
    int u = 4;

    verif_dir(line, u, i, filename);
}

void check_cmd(char *line, int i, char *filename)
{
    int c = 0;

    (my_strcmp(line, "\n")) ? 0 : c++;
    (my_strcmp(line, "live ")) ? v_live(line, i, filename) : c++;
    (my_strcmp(line, "ld ")) ? v_ld(line, i, filename) : c++;
    (my_strcmp(line, "st ")) ? v_st(line, i, filename) : c++;
    (my_strcmp(line, "add ")) ? v_op(line, i, filename) : c++;
    (my_strcmp(line, "sub ")) ? v_op(line, i, filename) : c++;
    (my_strcmp(line, "and ")) ? v_ctrl(line, i, filename) : c++;
    (my_strcmp(line, "or ")) ? v_ctrl(line, i, filename) : c++;
    (my_strcmp(line, "xor ")) ? v_ctrl(line, i, filename) : c++;
    (my_strcmp(line, "zjmp ")) ? v_zjmp(line, i, filename) : c++;
    (my_strcmp(line, "ldi ")) ? v_ldi(line, i, filename) : c++;
    (my_strcmp(line, "sti ")) ? v_sti(line, i, filename) : c++;
    (my_strcmp(line, "fork ")) ? v_zjmp(line, i, filename) : c++;
    (my_strcmp(line, "lld ")) ? v_ld(line, i, filename) : c++;
    (my_strcmp(line, "lldi ")) ? v_ldi(line, i, filename) : c++;
    (my_strcmp(line, "lfork ")) ? v_zjmp(line, i, filename) : c++;
    (my_strcmp(line, "aff ")) ? v_aff(line, i, filename) : c++;
    (c == 17) ? error(filename, i, 1, 1) : 0;
}

void verify_cmds(char **cmds, char *filename)
{
    char *mline;

    for (int i = 0; cmds[i]; i++) {
        mline = my_line(cmds[i]);
        check_cmd(mline, i, filename);
        free(mline);
    }
}