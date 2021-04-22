/*
** EPITECH PROJECT, 2019
** label
** File description:
** verif_command
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "op.h"
#include "asm.h"

char *my_line(char *line)
{
    char *out = malloc(sizeof(char) * (my_strlen(line) + 1));
    int dp = 0;
    int u = 0;
    int o = 0;

    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == LABEL_CHAR)
            (i != 0 && line[i - 1] == DIRECT_CHAR) ? 0 : dp++;
    if (dp != 0) {
        for (; line[u] != LABEL_CHAR && line[u] != '\0'; u++);
        u++;
    }
    for (; line[u] == ' ' && line[u] != '\0'; u++);
    for (; line[o + u] != '\0'; o++)
        out[o] = line[o + u];
    (out[0] == '\n') ? u = 0 : 0;
    out[o + u] = '\0';
    return (out);
}

int is_cmd(char *line)
{
    int c = 0;
    char *cmd = sp_l(line);

    (cmd[0] == COMMENT_CHAR) ? 0 : c++;
    (cmd[0] == NAME_CMD_STRING[0]) ? 0 : c++;
    (cmd[0] == COMMENT_CMD_STRING[0]) ? 0 : c++;
    (cmd[0] == '\n') ? 0 : c++;
    free (cmd);
    if (c == 4)
        return (1);
    else
        return (0);
}

int count_cmds(char **map)
{
    int c = 0;
    int wc = 0;
    char *spl;

    for (int i = 0; map[i] != NULL; i++) {
        c = 0;
        spl = sp_l(map[i]);
        (spl[0] == COMMENT_CHAR) ? 0 : c++;
        (spl[0] == NAME_CMD_STRING[0]) ? 0 : c++;
        (spl[0] == COMMENT_CMD_STRING[0]) ? 0 : c++;
        (spl[0] == '\n') ? 0 : c++;
        (c == 4) ? wc++ : 0;
        free(spl);
    }
    return (wc);
}

char **get_cmds(char **map)
{
    int u = 0;
    char **cmds = malloc(sizeof(char *) * (count_cmds(map) + 1));

    for (int i = 0; map[i] != 0; i++)
        if (is_cmd(map[i])) {
            cmds[u] = my_cpy(map[i]);
            u++;
        }
    cmds[u] = NULL;
    return (cmds);
}

char **verif_command(char **map, char *filename)
{
    char **cmds = get_cmds(map);
    int *cmds_len = get_cmds_len(cmds, count_cmds(map));
    int file_len = 0;

    for (int i = 0; cmds_len[i] != -1; i++)
        file_len += cmds_len[i];
    CMD_LEN = file_len;
    TOTAL_CMDS = cmds;
    verify_labels(cmds, filename);
    cmds = replace_labels(cmds, cmds_len);
    verify_cmds(cmds, filename);
    free(cmds_len);
    return (cmds);
}