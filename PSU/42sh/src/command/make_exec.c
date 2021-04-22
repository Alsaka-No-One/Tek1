/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** make_launch
*/

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "minishell.h"

void display_status(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == 8) {
            mputerror("Floating exception\n");
        } else {
            mputerror(strsignal(WTERMSIG(status)));
            mputerror("\n");
        }
    }
}

int exec_with_arg(char **argv, char **envp)
{
    if (execve(argv[0], argv, envp) == -1) {
        mputerror(argv[0]);
        mputerror(": Permission denied.\n");
    }
    exit (127);
}

int my_exec(data_t *data, char **arg)
{
    char ***envp = &data->envp;
    int r_value = 84;

    if (get_path(&arg, *envp) == 84)
        return (0);
    if (arg != NULL) {
        r_value = exec_with_arg(arg, *envp);
    }
    return (r_value);
}
