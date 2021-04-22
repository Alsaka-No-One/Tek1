/*
** EPITECH PROJECT, 2019
** label
** File description:
** replace_labels
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "op.h"
#include "asm.h"

void label_vline(char **cmds, char *label, int i, char *filename)
{
    int c_l = 0;
    int s = 0;
    char *spl;

    for (int u = 0; cmds[u]; u++) {
        spl = sp_l(cmds[u]);
        if (my_strcmp(spl, label)) {
            c_l++;
            s = u;
        }
        free(spl);
    }
    if (c_l == 0)
        error(filename, i, 7, 1);
    if (c_l > 1)
        error(filename, s, 8, 1);
}

char *get_vlabel(char *line, int i)
{
    int u = 0;
    char *label = malloc(sizeof(char) * (my_strlen(line) + 1));

    for (; (line[i] && ((line[i] >= 'a' && line[i] <= 'z') ||
        (line[i] >= '0' && line[i] <= '9') || line[i] == '_')); i++) {
            label[u] = line[i];
            u++;
        }
    label[u] = '\0';
    return (label);
}

void verify_label(char **line, int i, char *filename)
{
    char *label;

    for (int u = 0; line[i][u + 1]; u++)
        if (line[i][u] == DIRECT_CHAR && line[i][u + 1] == LABEL_CHAR) {
            label = get_vlabel(line[i], u + 2);
            label_vline(line, label, i, filename);
            free(label);
        }
}

void verify_labels(char **cmds, char *filename)
{
    for (int i = 0; cmds[i]; i++)
        verify_label(cmds, i, filename);
}