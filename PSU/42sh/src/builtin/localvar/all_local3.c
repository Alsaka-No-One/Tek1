/*
** EPITECH PROJECT, 2019
** built-in
** File description:
** alias
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mlib.h"

int strcmpalias(char *line, char *alias)
{
    int i = 0;

    if (!line || !alias)
        return (0);
    for (; line[i]; i++) {
        if (!alias[i])
            return (0);
        if (line[i] != alias[i])
            return (0);
    }
    return (1);
}

char *get_full_line(char **tab)
{
    int size = 0;
    char *line;
    int p = 0;

    for (int i = 0; tab[i]; i++)
        size += strlen(tab[i]);
    line = malloc(sizeof(char) * (size + 10));
    for (int i = 0; tab[i]; i++) {
        for (int u = 0; tab[i][u]; u++) {
            line[p] = tab[i][u];
            p++;
        }
        line[p] = (tab[i + 1]) ? ' ' : '\n';
        p++;
    }
    line[p] = '\0';
    return (line);
}

char **init_sets(void)
{
    char **sets = malloc(sizeof(char *));

    sets[0] = NULL;
    return (sets);
}

int only_set(char *line)
{
    int i = 3;

    for (; line[i] && line[i] == ' '; i++);
    if (line[i] == '\n' || line[i] == '\0')
        return (1);
    return (0);
}

int print_set(char *line, char **sets)
{
    int i = 0;

    if (only_set(line)) {
        for (; sets[i]; i++)
            mputstr(sets[i]);
        (i != 0) ? mputstr("\n") : 0;
        return (1);
    }
    return (0);
}