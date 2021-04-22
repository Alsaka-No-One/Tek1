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

char *get_set_dest(char *line)
{
    char *alias = malloc(sizeof(char) * (strlen(line) + 1));
    int i = 3;
    int u = 0;

    alias[0] = '\0';
    for (; line[i] && line[i] == ' '; i++);
    if (line[i]) {
        for (; line[i] && line[i] != ' '
            && line[i] != '=' && line[i] != '\n'; i++);
        i++;
    }
    for (; line[i] && (line[i] == ' ' || line[i] == '='); i++);
    if (line[i]) {
        for (; line[i] && line[i] != ' '
            && line[i] != '=' && line[i] != '\n'; i++) {
            alias[u] = line[i];
            u++;
        }
        alias[u] = '\0';
    }
    return (alias);
}

char *get_set(char *line)
{
    char *alias = malloc(sizeof(char) * (strlen(line) + 1));
    int i = 3;
    int u = 0;

    alias[0] = '\0';
    for (; line[i] && line[i] == ' '; i++);
    if (line[i]) {
        for (; line[i] && line[i] != ' '
            && line[i] != '=' && line[i] != '\n'; i++) {
            alias[u] = line[i];
            u++;
        }
        alias[u] = '\0';
    }
    return (alias);
}

int find_set(char *input, char **env, int mv)
{
    int i;
    int verif;

    for (int u = 0; env[u] != NULL; u++) {
        verif = 0;
        for (i = 0; input[i + mv] && env[u] && input[i + mv] != ' '
            && input[i + mv] != '\n' && input[i + mv] != '='; i++)
                (input[i + mv] != env[u][i]) ? verif++ : 0;
        if (verif == 0 && env[u][i] == '\t')
            return (u);
    }
    return (-1);
}

char *make_set_line(char *input)
{
    char *new_line = malloc(sizeof(char) * (strlen(input) + 1));
    int i = 4;
    int u = 0;

    for (; input[i] && input[i] != ' '
        && input[i] != '\n' && input[i] != '='; i++) {
        new_line[u] = input[i];
        u++;
    }
    new_line[u] = '\t';
    u++;
    for (; input[i] == ' ' || input[i] == '='; i++);
    for (; input[i] != ' ' && input[i] != '\0' && input[i] != '\n'; i++) {
        new_line[u] = input[i];
        u++;
    }
    new_line[u] = '\0';
    return (new_line);
}