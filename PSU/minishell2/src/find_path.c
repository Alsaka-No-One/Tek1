/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** find_path
*/

#include "shell.h"

static void parent_process(int i)
{
    int status;

    waitpid(i, &status, 0);
    if (WIFSIGNALED(status)) {
        my_putstr(strsignal(WTERMSIG(status)));
        my_putstr("\n");
    }
}

static int find_exec(char *path, char **arg, char **env)
{
    int i = 0;

    if ((i = fork()) < 0)
        return (ERROR);
    else if (i == 0)
        execve(path, arg, env);
    else
        parent_process(i);
    free(path);
    return (1);
}

static int check_access(char *path, char **arg, char **envp, int  *j)
{
    if (access(path, F_OK) == 0) {
        *j = 5;
        return (find_exec(path, arg, envp));
    }
    return (0);
}

static int access_file(char **arg, char **envp, int i)
{
    static int j = 5;
    int k = 0;
    char *path = NULL;

    if ((path = malloc(sizeof(char) * (my_strlen(envp[i]) + 1))) == NULL)
        return (ERROR);
    for (; envp[i][j] != ':'; j++, k++) {
        if (envp[i][j] == '\0') {
            j = 5;
            return (0);
        }
        path[k] = envp[i][j];
    }
    j++;
    path[k] = '\0';
    path = my_strcat_path(path, arg[0]);
    if (check_access(path, arg, envp, &j) == 1)
        return (1);
    free(path);
    return (0);
}

int find_path(char **arg, char **envp)
{
    int i = 0;
    int j = 0;

    while (envp[i] != NULL && my_strcomp_env("PATH", envp[i]) != 1)
        i++;
    for (; j < 8; j++)
        if ((access_file(arg, envp, i)) == 1)
            break;
    if (j == 8)
        return (ERROR);
    return (SUCCESS);
}