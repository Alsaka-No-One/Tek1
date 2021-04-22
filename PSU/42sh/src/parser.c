/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** binary_tree
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "mlib.h"
#include "minishell.h"

int translate_symbol(char *symbol)
{
    if (symbol == NULL)
        return (EMPTY);
    if (mstrsame(symbol, ";") == TRUE)
        return (COMA);
    if (mstrsame(symbol, "&&") == TRUE)
        return (ESPER);
    if (mstrsame(symbol, "||") == TRUE)
        return (DOUBLE_PIPE);
    if (mstrsame(symbol, "|") == TRUE)
        return (PIPE);
    if (mstrsame(symbol, "<") == TRUE)
        return (SIMPLE_LEFT);
    if (mstrsame(symbol, ">") == TRUE)
        return (SIMPLE_RIGHT);
    if (mstrsame(symbol, ">>") == TRUE)
        return (DOUBLE_RIGHT);
    if (mstrsame(symbol, "<<") == TRUE)
        return (DOUBLE_LEFT);
    return (ERROR);
}

static char *get_symbol(char *input, int *i, char symb, int *save)
{
    char *symbol = malloc(sizeof(char) * 3);
    int index = 0;

    if (symbol == NULL)
        return (NULL);
    do {
        symbol[index] = input[*i];
        *i += 1;
        index += 1;
    } while (input[*i] == symb && input[*i] != '\0');
    symbol[index] = '\0';
    *save = *i;
    return (symbol);
}

static int check(char **string, char *input, int *i, int *save)
{
    char *temp = NULL;

    if ((input[*i] == ';' || input[*i] == '&' || input[*i] == '|'
        || input[*i] == '<' || input[*i] == '>') && input[*i] != '\0') {
        temp = copy_command(input, *save);
        *string = temp;
        if (*string == NULL)
            return (ERROR);
        return (SUCCESS);
    }
    return (ERROR);
}

int is_next_symbol(char *input, int start)
{
    size_t i = start;

    for ( ; input[i] != '\0' && input[i] != '\n'; i++) {
        if ((input[i] == ';' || input[i] == '|' || input[i] == '&'
            || input[i] == '<' || input[i] == '>') && input[i] != '\0') {
            return (SUCCESS);
        }
    }
    return (ERROR);
}

int parser(char *input, node_t **tree, data_t *data)
{
    int save = 0, i = 0;
    char *string = NULL;
    char *symb = NULL;

    for (; input[i] != '\0' && input[i] != '\n'; i++) {
        if (is_next_symbol(input, save) == ERROR) {
            string = copy_command(input, save);
            final_add(tree, reverse_alias(marg2(string), data->aliases));
            free(string);
            return (SUCCESS);
        }
        if (check(&string, input, &i, &save) == SUCCESS) {
            symb = get_symbol(input, &i, input[i], &save);
            add_element_tree(tree, symb,
            reverse_alias(marg2(string), data->aliases));
            free(symb);
            free(string);
            string = NULL;
        }
    }
    return (SUCCESS);
}