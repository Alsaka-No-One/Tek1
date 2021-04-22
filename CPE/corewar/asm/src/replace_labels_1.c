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

char *get_label(char *line, int i)
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

int is_label(char c)
{
    if (c != '\0' && ((c >= 'a' && c <= 'z')
        || (c >= '0' && c <= '9') || c == '_'))
        return (1);
    return (0);
}

char *replace(char **line, int u, int *cmds_len, int i)
{
    char *label = get_label(line[i], u);
    char *nw_label = my_itoa(new_label(line, label, cmds_len, i));
    char *nw_line = malloc(sizeof(char) * (my_strlen(line[i]) + 1));
    int w = 0;
    int p = 0;
    int z = 1;

    for (; w + 1 < u; w++)
        nw_line[w] = line[i][w];
    for (; p < my_strlen(nw_label); p++)
        nw_line[w + p] = nw_label[p];
    for (; is_label(line[i][w + z]); z++);
    for (; line[i][w + z]; z++) {
        nw_line[w + p] = line[i][w + z];
        p++;
    }
    nw_line[w + p] = '\0';
    free(nw_label);
    free(label);
    free(line[i]);
    return (nw_line);
}

char *replace_label(char **line, int *cmds_len, int i)
{
    for (int u = 0; line[i][u + 1]; u++)
        if (line[i][u] == DIRECT_CHAR && line[i][u + 1] == LABEL_CHAR)
            line[i] = replace(line, u + 2, cmds_len, i);
    return (line[i]);
}

char **replace_labels(char **cmds, int *cmds_len)
{
    for (int i = 0; cmds[i]; i++)
        cmds[i] = replace_label(cmds, cmds_len, i);
    return (cmds);
}