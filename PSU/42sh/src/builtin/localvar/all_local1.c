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

char **set_sets(char *input, char **sets)
{
    int i = 0;
    int line = find_set(input, sets, 4);

    if (strlen(input) <= 7)
        return (sets);
    if (line >= 0)
        sets[line] = make_set_line(input);
    else {
        sets = my_arrcpy(sets, 1);
        for (; sets[i] != NULL; i++);
        sets[i] = make_set_line(input);
        sets[i + 1] = NULL;
    }
    return (sets);
}

char **add_set(char *line, char **sets)
{
    char *set = get_set(line);

    if (!set[0])
        return (sets);
    if (set[0] < 'A' || (set[0] > 'Z' && set[0] < 'a') || set[0] > 'z'){
        puts("set: Variable name must begin with a letter.\n");
        return (sets);
    }
    return (set_sets(line, sets));
}

int my_set(data_t *data, char **tab)
{
    char *line = get_full_line(tab);

    if (!print_set(line, data->sets))
        data->sets = add_set(line, data->sets);
    return (SUCCESS);
}

static int norme(int i, int line, char **unset, char **set)
{
    if (i >= line) {
        unset[i] = malloc(sizeof(char) * (strlen(set[i + 1]) + 1));
        if (unset[i] == NULL)
            return (ERROR);
        strcpy(unset[i], set[i + 1]);
    }
    return (SUCCESS);
}

int my_unset(data_t *data, char **tab)
{
    int i = 0;
    char *input = get_full_line(tab);
    int line = find_set(input, data->sets, 6);
    char **unset;

    for (; data->sets[i] != NULL; i++);
    unset = malloc(sizeof(char *) * i);
    if (strlen(input) <= 5 || line < 0)
        return (ERROR);
    for (i = 0 ; data->sets[i + 1] != NULL; i++) {
        if (i < line) {
            unset[i] = malloc(sizeof(char) * (strlen(data->sets[i]) + 1));
            strcpy(unset[i], data->sets[i]);
        }
        if (norme(i, line, unset, data->sets) == ERROR)
            return (ERROR);
    }
    unset[i] = NULL;
    data->sets = unset;
    return (SUCCESS);
}