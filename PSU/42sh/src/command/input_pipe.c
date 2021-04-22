/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** input_pipe
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "minishell.h"

static int open_file(node_t *node)
{
    int fd = 0;
    char **name = NULL;

    if (node->right->symbol == EMPTY)
        name = node->right->command;
    else
        name = node->left->command;
    if (name == NULL)
        return (ERROR);
    fd = open(name[0], O_RDONLY);
    if (fd == -1) {
        mputerror(name[0]);
        mputerror(": No such file or directory.\n");
        return (-2);
    }
    return (fd);
}

int input_pipe(node_t *tree)
{
    while (tree->right && tree->symbol != PIPE && tree->symbol != COMA ) {
        if (tree->symbol == SIMPLE_LEFT || tree->symbol == DOUBLE_LEFT)
            return (open_file(tree));
        tree = tree->right;
    }
    return (-1);
}