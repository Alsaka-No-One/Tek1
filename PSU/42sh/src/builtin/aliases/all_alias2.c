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

char *get_dest(char *line)
{
    char *alias = malloc(sizeof(char) * (strlen(line) + 1));
    int i = 5;
    int u = 0;

    alias[0] = '\0';
    for (; line[i] && line[i] == ' '; i++);
    if (line[i])
        for (; line[i] && line[i] != ' '; i++);
    for (; line[i] && line[i] == ' '; i++);
    if (line[i]) {
        for (; line[i] && line[i] != ' '; i++) {
            alias[u] = line[i];
            u++;
        }
        alias[u] = '\0';
    }
    return (alias);
}

char *get_alias(char *line)
{
    char *alias = malloc(sizeof(char) * (strlen(line) + 1));
    int i = 5;
    int u = 0;

    alias[0] = '\0';
    for (; line[i] && line[i] == ' '; i++);
    if (line[i]) {
        for (; line[i] && line[i] != ' '; i++) {
            alias[u] = line[i];
            u++;
        }
        alias[u] = '\0';
    }
    return (alias);
}

int find_alias(char *input, char **env, int mv)
{
    int i;
    int verif;

    for (int u = 0; env[u] != NULL; u++) {
        verif = 0;
        for (i = 0; input[i + mv] && env[u]
            && input[i + mv] != ' ' && input[i + mv] != '\n'; i++)
                (input[i + mv] != env[u][i]) ? verif++ : 0;
        if (verif == 0 && env[u][i] == '\t')
            return (u);
    }
    return (-1);
}

char *make_alias_line(char *input)
{
    char *new_line = malloc(sizeof(char) * (my_strlen(input) + 1));
    int i = 6;

    for (; input[i] != ' ' && input[i] != '\0' && input[i] != '\n'; i++)
        new_line[i - 6] = input[i];
    new_line[i - 6] = '\t';
    i++;
    for (; input[i] != ' ' && input[i] != '\0' && input[i] != '\n'; i++)
        new_line[i - 6] = input[i];
    new_line[i - 6] = '\0';
    return (new_line);
}

int alias(data_t *data, char **tab)
{
    char *line = get_full_line(tab);

    if (!print_alias(line, data->aliases))
        data->aliases = add_alias(line, data->aliases);
    return (SUCCESS);
}