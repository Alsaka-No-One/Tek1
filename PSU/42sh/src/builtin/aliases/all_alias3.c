/*
** EPITECH PROJECT, 2019
** built-in
** File description:
** alias
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"
#include "mlib.h"

char *replaced_alias(char *line)
{
    int i = 0;
    int u = 0;
    char *new = malloc(sizeof(char) * (strlen(line) + 1));

    for (; line[i] && line[i] != '\t'; i++);
    i++;
    for (; line[i]; i++) {
        new[u] = line[i];
        u++;
    }
    new[u] = '\0';
    return (new);
}

char **reverse_alias(char **lines, char **aliases)
{
    for (int i = 0; aliases[i]; i++) {
        if (strcmpalias(lines[0], aliases[i]))
            lines[0] = replaced_alias(aliases[i]);
    }
    return (lines);
}

char **init_aliases(void)
{
    char **aliases = malloc(sizeof(char *));

    aliases[0] = NULL;
    return (aliases);
}

int only_alias(char *line)
{
    int i = 5;

    for (; line[i] && line[i] == ' '; i++);
    if (line[i])
        for (; line[i] && line[i] != ' '; i++);
    for (; line[i] && line[i] == ' '; i++);
    if (line[i])
        return (0);
    return (1);
}

int print_alias(char *line, char **aliases)
{
    int i = 0;

    if (only_alias(line)) {
        for (; aliases[i]; i++)
            mputstr(aliases[i]);
        (i != 0) ? mputstr("\n") : 0;
        return (1);
    }
    return (0);
}