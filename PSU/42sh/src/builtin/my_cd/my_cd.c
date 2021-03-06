/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** cd function
*/

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "mlib.h"

static int error_cd(data_t *data, char **input)
{
    int ac = 0;

    for ( ; input[ac] ; ac++);
    if (ac == 1) {
        my_cd_no_arg(data);
        return (ERROR);
    }
    if (ac > 2) {
        mputstr("cd: Too many arguments.\n");
        return (ERROR);
    }
    if (mstrsame(input[1], "-\0") == TRUE) {
        my_cd_malus(data);
        return (ERROR);
    }
    if (access(input[1], R_OK) == -1) {
        perror(input[1]);
        return (ERROR);
    }
    return (SUCCESS);
}

int my_cd(data_t *data, char **input)
{
    char *path = NULL;

    if (error_cd(data, input) == ERROR)
        return (SUCCESS);
    if (set_old_pwd(data) == ERROR)
        return (ERROR);
    path = input[1];
    if (chdir(path) == -1) {
        mputstr(path);
        mputstr(": Not a directory.\n");
        return (ERROR);
    }
    if ((set_pwd(data)) == ERROR)
        return (ERROR);
    return (SUCCESS);
}
