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

char **my_arrcpy(char **array, int add)
{
    char **out;
    int i = 0;

    for (; array[i] != NULL; i++);
    out = malloc(sizeof(char *) * (i + 1 + add));
    for (i = 0; array[i] != NULL; i++){
        out[i] = malloc(sizeof(char) * (strlen(array[i]) + 1));
        strcpy(out[i], array[i]);
    }
    out[i] = NULL;
    return (out);
}

char **set_aliases(char *input, char **aliases)
{
    int i = 0;
    int line = find_alias(input, aliases, 6);

    if (my_strlen(input) <= 7)
        return (aliases);
    if (line >= 0)
        aliases[line] = make_alias_line(input);
    else {
        aliases = my_arrcpy(aliases, 1);
        for (; aliases[i] != NULL; i++);
        aliases[i] = make_alias_line(input);
        aliases[i + 1] = NULL;
    }
    return (aliases);
}

char **add_alias(char *line, char **aliases)
{
    char *alias = get_alias(line);
    char *dest = get_dest(line);

    if (!alias[0] || !dest[0])
        return (aliases);
    return (set_aliases(line, aliases));
}

static int norme(int i, int line, char **unset, char **alias)
{
    if (i >= line) {
        unset[i] =
            malloc(sizeof(char) * (strlen(alias[i + 1]) + 1));
        if (unset[i] == NULL)
            return (ERROR);
        strcpy(unset[i], alias[i + 1]);
    }
    return (SUCCESS);
}

int unalias(data_t *data, char **tab)
{
    int i = 0;
    char *input = get_full_line(tab);
    int line = find_alias(input, data->aliases, 8);
    char **unset;

    for (; data->aliases[i] != NULL; i++);
    unset = malloc(sizeof(char *) * i);
    if (my_strlen(input) <= 7 || line < 0)
        return (ERROR);
    for (i = 0 ; data->aliases[i + 1] != NULL; i++) {
        if (i < line) {
            unset[i] = malloc(sizeof(char) * (strlen(data->aliases[i]) + 1));
            strcpy(unset[i], data->aliases[i]);
        }
        if (norme(i, line, unset, data->aliases) == ERROR)
            return (ERROR);
    }
    unset[i] = NULL;
    data->aliases = unset;
    return (SUCCESS);
}