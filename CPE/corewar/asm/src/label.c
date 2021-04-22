/*
** EPITECH PROJECT, 2019
** label
** File description:
** label
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "op.h"
#include "asm.h"

int nb_l(char *filename)
{
    FILE *file = fopen(filename, "r");
    char *line = NULL;
    size_t len = 0;
    int i = 0;

    if (file == NULL) {
        write(2, "Error in function open: No such file or directory.\n", 51);
        exit (84);
    }
    for (; (getline(&line, &len, file) >= 0); i++);
    free(line);
    fclose(file);
    return (i);
}

int my_strlen(char const *str)
{
    int i = 0;

    for (; str && str[i]; i++);
    return (i);
}

char *my_cpy(char *str)
{
    char *out = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    for (; str[i]; i++)
        out[i] = str[i];
    out[i] = '\0';
    return (out);
}

char **get_zork(char *filename)
{
    char **map = malloc(sizeof(char *) * (nb_l(filename) + 1));
    char **cmds;
    FILE *file = fopen(filename, "r");
    char *line = NULL;
    size_t len = 0;
    int i = 0;

    for (; (getline(&line, &len, file) >= 0); i++) {
        map[i] = my_cpy(line);
    }
    free(line);
    map[i] = NULL;
    fclose(file);
    cmds = analyse(map, filename);
    write_zork(map, cmds, filename);
    for (int p = 0; cmds[p]; p++)
        free(cmds[p]);
    free(cmds);
    return (map);
}

int label(char *filename)
{
    char **map = get_zork(filename);
    for (int i = 0; map[i]; i++)
        free(map[i]);
    free(map);
    return (0);
}