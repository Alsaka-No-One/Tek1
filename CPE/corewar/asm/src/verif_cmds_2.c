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

void v_sti(char *line, int i, char *filename)
{
    int u = 3;

    verif_reg(line, u, i, filename);
    u = get_c(line, u, SEPARATOR_CHAR) + 1;
    verif_all(line, u, i, filename);
    u = get_c(line, u, SEPARATOR_CHAR) + 1;
    verif_dnr(line, u, i, filename);
}

void v_ldi(char *line, int i, char *filename)
{
    int u = 4;

    verif_all(line, u, i, filename);
    u = get_c(line, u, SEPARATOR_CHAR) + 1;
    verif_dnr(line, u, i, filename);
    u = get_c(line, u, SEPARATOR_CHAR) + 1;
    verif_reg(line, u, i, filename);
}

void v_zjmp(char *line, int i, char *filename)
{
    int u = 5;

    verif_dir(line, u, i, filename);
}

void v_ctrl(char *line, int i, char *filename)
{
    int u = 3;

    verif_all(line, u, i, filename);
    u = get_c(line, u, SEPARATOR_CHAR) + 1;
    verif_all(line, u, i, filename);
    u = get_c(line, u, SEPARATOR_CHAR) + 1;
    verif_reg(line, u, i, filename);
}

void v_op(char *line, int i, char *filename)
{
    int u = 3;

    verif_reg(line, u, i, filename);
    u = get_c(line, u, SEPARATOR_CHAR) + 1;
    verif_reg(line, u, i, filename);
    u = get_c(line, u, SEPARATOR_CHAR) + 1;
    verif_reg(line, u, i, filename);
}