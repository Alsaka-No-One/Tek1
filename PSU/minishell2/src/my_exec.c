/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** my_exec
*/

#include "shell.h"

static void child_process(char **arg, char **envp)
{
    execve(arg[0], arg, envp);
}

static void parent_process(int i)
{
    int status;

    waitpid(i, &status, 0);
    if (WIFSIGNALED(status)) {
        my_putstr(strsignal(WTERMSIG(status)));
        my_putstr("\n");
    }
}

int my_exec(char **arg, char **envp)
{
    int i = 0;

    if ((i = fork()) < 0)
        return (ERROR);
    else if (i == 0)
        child_process(arg, envp);
    else
        parent_process(i);
    return (SUCCESS);
}