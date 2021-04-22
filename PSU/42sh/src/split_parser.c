/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** split_parser
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mlib.h"
#include "minishell.h"

static node_t *initialize_tree(void)
{
    node_t *tree = malloc(sizeof(node_t));

    if (tree == NULL)
        return (NULL);
    tree->symbol = EMPTY;
    tree->command = NULL;
    tree->left = NULL;
    tree->right = NULL;
    return (tree);
}

static void display_graph(int size, node_t *node)
{
    printf("----------------------->currnet node %d %d\n", size, node->symbol);
    if (node->command != NULL)
        for (int i = 0 ; node->command[i] != NULL ; i++)
            printf("node %d left, current %s\n", size, node->command[i]);
    if (node->left != NULL)
        for (int i = 0 ; node->left->command[i] != NULL ; i++)
            printf("node %d left, command %s\n", size, node->left->command[i]);
    if (node->right != NULL) {
        for (int i = 0 ; node->right->command[i] != NULL ; i++)
            printf("node %d right, command %s\n",
                size,  node->right->command[i]);
        display_graph(size + 1, node->right);
    }
}

static int check_before_after(char *input, int save)
{
    int status = 0;

    for (int i = save; i >= 0; i--)
        if ((input[i] >= 'A' && input[i] <= 'Z')
            || (input[i] >= 'a' && input[i] <= 'z')) {
            status += 1;
            break;
        }
    if (input[save] == input[save + 1])
        save += 1;
    for (int i = save + 1; input[i] != '|' && input[i] != '&'
        && input[i] != '>' && input[i] != '<' && input[i] != '\0'; i++) {
        if ((input[i] >= 'A' && input[i] <= 'Z')
            || (input[i] >= 'a' && input[i] <= 'z')) {
            status += 1;
            break;
            }
        }
    if (status == 2)
        return (SUCCESS);
    return (ERROR);
}

static int error_syntax(char *input)
{
    int status = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '|' || input[i] == '&' || input[i] == '>'
            || input[i] == '<') {
            status = check_before_after(input, i + 1);
        }
        if (status == ERROR)
            return (ERROR);
    }
    return (SUCCESS);
}

int split_parser(char *input, data_t *data)
{
    node_t *tree = NULL;

    (void)display_graph;
    data->child_nb = 0;
    if (error_syntax(input) == ERROR) {
        mputerror("Invalid syntax\n");
        return (SUCCESS);
    }
    tree = initialize_tree();
    if (is_next_symbol(input, 0) == ERROR)
        final_add(&tree, reverse_alias(marg2(input), data->aliases));
    else
        if (parser(input, &tree, data) == ERROR)
            return (ERROR);
    command_handler(tree->right, data, (int[2]){-1, -1});
    return (SUCCESS);
}
