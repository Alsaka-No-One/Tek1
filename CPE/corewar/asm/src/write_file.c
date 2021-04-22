/*
** EPITECH PROJECT, 2019
** label
** File description:
** write_file
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "op.h"
#include "asm.h"

void write_name(char *line, int out)
{
    int i = 7;
    int ct_line = 0;
    char file_header[6] = {0x00, 0xEA, 0x83, 0xF3};

    write(out, file_header, 4);
    for ( ; line[i] != '"' && line[i] != '\0'; i++) {
        write(out, &line[i], 1);
        ct_line++;
    }
    fill_with_zero(out, ct_line, 1);
}

void write_comment(char *line, int out)
{
    int i = 10;
    int ct_line = 0;
    char file_header = 0x00;

    for (int u = 0; u != 11; u++)
        write(out, &file_header, 1);
    write(out, &CMD_LEN, 1);
    for (; line[i] != '"' && line[i] != '\0'; i++) {
        write(out, &line[i], 1);
        ct_line++;
    }
    fill_with_zero(out, ct_line, 2);
}

void write_header(char *line, int out)
{
    char *spl = sp_l(line);

    if (my_strcmp(spl, NAME_CMD_STRING)) {
        write_name(spl, out);
        free(spl);
        return;
    }
    if (my_strcmp(spl, COMMENT_CMD_STRING)) {
        write_comment(spl, out);
        free(spl);
        return;
    }
    free(spl);
    return;
}

char *my_ass(char *ass)
{
    int i = 0;
    char *out = (char *) malloc(sizeof(char) * (my_strlen(ass) + 5));

    for (; ass[i] != '\0'; i++)
        out[i] = ass[i];
    if (ass[i - 1] == 's' && ass[i - 2] == '.')
        i -= 2;
    out[i] = '.';
    out[i + 1] = 'c';
    out[i + 2] = 'o';
    out[i + 3] = 'r';
    out[i + 4] = '\0';
    return (out);
}

void write_zork(char **map, char **cmds, char *filename)
{
    char *mass = my_ass(filename);
    FILE * pre_out = fopen(mass, "w");
    int out;
    char *mline;

    fclose(pre_out);
    out = open(mass, O_WRONLY | O_APPEND, 0644);
    free(mass);
    for (int i = 0; map[i]; i++)
        write_header(map[i], out);
    for (int i = 0; cmds[i]; i++) {
        mline = my_line(cmds[i]);
        write_cmds(mline, out);
        free(mline);
    }
    close(out);
}