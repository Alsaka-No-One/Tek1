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

void verif_all(char *line, int u, int li, char *filename)
{
    int i = u;
    int cpi = u;
    int nb = nxtnbr(line, &cpi);

    for (; line[i] && line[i] == ' '; i++);
    if ((((line[i] > '9' || line[i] < '0') && line[i] != '-'))
        && line[i] != REG_CHAR && line[i] != DIRECT_CHAR)
        error(filename, li, 2, 1);
    if ((line[i] == REG_CHAR || line[i] == DIRECT_CHAR) &&
        (!line[i + 1] || ((line[i + 1] > '9' || line[i + 1] < '0')
            && line[i + 1] != '-')))
        error(filename, li, 2, 1);
    if (line[i] == REG_CHAR && (nb < 1 || nb > 16))
        error(filename, li, 11, 1);
}

void verif_ind(char *line, int u, int li, char *filename)
{
    int i = u;

    for (; line[i] && line[i] == ' '; i++);
    if ((line[i] > '9' || line[i] < '0') && line[i] != '-')
        error(filename, li, 2, 1);
}

void verif_reg(char *line, int u, int li, char *filename)
{
    int i = u;
    int cpi = u;
    int nb = nxtnbr(line, &cpi);

    for (; line[i] && line[i] == ' '; i++);
    if (!line[i + 1])
        error(filename, li, 2, 1);
    if (line[i] != REG_CHAR ||
        (line[i + 1] > '9' || line[i + 1] < '0'))
        error(filename, li, 2, 1);
    if (nb < 1 || nb > 16)
        error(filename, li, 11, 1);
}

void verif_dir(char *line, int u, int li, char *filename)
{
    int i = u;

    for (; line[i] && line[i] == ' '; i++);
    if (!line[i + 1])
        error(filename, li, 2, 1);
    if (line[i] != DIRECT_CHAR ||
        ((line[i + 1] > '9' || line[i + 1] < '0') && line[i + 1] != '-'))
            error(filename, li, 2, 1);
}

void v_aff(char *line, int i, char *filename)
{
    int u = 3;

    verif_reg(line, u, i, filename);
}