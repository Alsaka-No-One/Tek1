/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** binary_tree
*/

#include <stdio.h>
#include <stdlib.h>
#include "mlib.h"
#include "minishell.h"

int add_right(node_t **right, node_t **tmp_tree, int symbol, char **command)
{
    (*right)->left = malloc(sizeof(node_t));

    if ((*right)->left == NULL)
        return (ERROR);
    (*right)->symbol = symbol;
    (*right)->command = NULL;
    (*right)->right = NULL;
    add_left(&(*right)->left, right, command);
    (*tmp_tree)->right = *right;
    return (SUCCESS);
}

int add_left(node_t **left, node_t **tmp_tree, char **command)
{
    (*left)->symbol = EMPTY;
    (*left)->command = marr_cln(command);
    if ((*left)->command == NULL)
        return (ERROR);
    (*left)->left = NULL;
    (*left)->right = NULL;
    (*tmp_tree)->left = *left;
    return (SUCCESS);
}

int final_add(node_t **tree, char **command)
{
    node_t *right = malloc(sizeof(node_t));
    node_t *tmp_tree = *tree;

    if (right == NULL || !command)
        return (ERROR);
    while (tmp_tree->right != NULL)
        tmp_tree = tmp_tree->right;
    right->symbol = EMPTY;
    right->command = marr_cln(command);
    if (right->command == NULL)
        return (ERROR);
    right->right = NULL;
    right->left = NULL;
    tmp_tree->right = right;
    return (SUCCESS);
}

int add_element_tree(node_t **tree, char *symbol, char **command)
{
    node_t *node_right = malloc(sizeof(node_t));
    node_t *tmp_tree = *tree;

    if (node_right == NULL || !command || !symbol)
        return (ERROR);
    while (tmp_tree->right != NULL)
        tmp_tree = tmp_tree->right;
    if (add_right(&node_right, &tmp_tree, translate_symbol(symbol),
        command) == ERROR)
        return (ERROR);
    return (SUCCESS);
}
