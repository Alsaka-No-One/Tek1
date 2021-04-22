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

void verif_dnr(char *line, int u, int li, char *filename)
{
    int i = u;
    int cpi = u;
    int nb = nxtnbr(line, &cpi);

    for (; line[i] && line[i] == ' '; i++);
    if (!line[i + 1])
        error(filename, li, 2, 1);
    if ((line[i] != REG_CHAR && line[i] != DIRECT_CHAR) ||
        ((line[i + 1] > '9' || line[i + 1] < '0') && line[i + 1] != '-'))
        error(filename, li, 2, 1);
    if (line[i] == 'r' && (nb < 1 || nb > 16))
        error(filename, li, 11, 1);
}

void verif_inr(char *line, int u, int li, char *filename)
{
    int i = u;
    int cpi = u;
    int nb = nxtnbr(line, &cpi);

    for (; line[i] && line[i] == ' '; i++);
    if ((((line[i] > '9' || line[i] < '0') && line[i] != '-'))
        || line[i] == REG_CHAR)
        cpi = u;
    else
        error(filename, li, 2, 1);
    if (line[i] == REG_CHAR &&
        (!line[i + 1] || ((line[i + 1] > '9' || line[i + 1] < '0')
            && line[i + 1] != '-')))
        error(filename, li, 2, 1);
    if (line[i] == 'r' && (nb < 1 || nb > 16))
        error(filename, li, 11, 1);
}

void verif_dni(char *line, int u, int li, char *filename)
{
    int i = u;
    int cpi = u;

    for (; line[i] && line[i] == ' '; i++);
    if ((((line[i] > '9' || line[i] < '0') && line[i] != '-'))
        || line[i] == DIRECT_CHAR)
        u = cpi;
    else
        error(filename, li, 2, 1);
    if (line[i] == DIRECT_CHAR &&
        (!line[i + 1] || ((line[i + 1] > '9' || line[i + 1] < '0')
            && line[i + 1] != '-')))
        error(filename, li, 2, 1);
}