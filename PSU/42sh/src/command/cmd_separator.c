/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** cmd_separator
*/

#include <stdio.h>
#include "minishell.h"

int cmd_seperator(node_t *tree, data_t *data, int prev_pipe[2])
{
    if (tree->symbol == COMA) {
        command_handler(tree->left, data, (int[2]){-1, -1});
        wait_child(data);
        command_handler(tree->right, data, (int[2]){-1, -1});
    } else if (tree->symbol == ESPER) {
        create_link(tree->left, data, prev_pipe, (int[2]){-1, -1});
        if (wait_child(data) == 0)
            command_handler(tree->right, data, (int[2]){-1, -1});
        else
            command_handler(tree->right->right, data, (int[2]){-1, -1});
    } else {
        create_link(tree->left, data, prev_pipe, (int[2]){-1, -1});
        if (wait_child(data) != 0)
            command_handler(tree->right, data, (int[2]){-1, -1});
        else
            command_handler(tree->right->right, data, (int[2]){-1, -1});
    }
    return (SUCCESS);
}