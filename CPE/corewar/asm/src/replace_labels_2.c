/*
** EPITECH PROJECT, 2019
** label
** File description:
** my_puts
*/

#include <unistd.h>
#include "asm.h"
#include <stdlib.h>

int label_line(char **cmds, char *label)
{
    char *spl;

    for (int i = 0; cmds[i]; i++) {
        spl = sp_l(cmds[i]);
        if (my_strcmp(spl, label)) {
            free(spl);
            return (i);
        }
        free(spl);
    }
    return (-1);
}

int new_label(char **cmds, char *label, int *cmds_len, int i)
{
    int label_l = label_line(cmds, label);
    int nw_label = 0;

    for (; (label_l - i > 0); i++)
        nw_label += cmds_len[i];
    for (; (label_l - i < 0); i--)
        nw_label -= cmds_len[i - 1];
    return (nw_label);
}

void my_puts(int c, char *line)
{
    write(c, line, my_strlen(line));
}