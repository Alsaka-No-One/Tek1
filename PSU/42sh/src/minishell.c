/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "minishell.h"
#include "mlib.h"

char *get_input(void)
{
    char *temp = NULL;
    size_t len = 0;

    if (isatty(0) == 1)
        mputstr("$> ");
    if (getline(&temp, &len, stdin) == -1) {
        if (isatty(0) == 1)
            mputstr("exit\n");
        free(temp);
        return (NULL);
    }
    for (int i = 0 ; temp[i] ; i++)
        if (temp[i] == '\n')
            temp[i] = '\0';
    return (temp);
}

void handler1(int sig)
{
    (void)sig;
    if (isatty(0) == 1) {
        mputstr("\n$> ");
    }
}

int minishell(char **envp)
{
    char *input = NULL;
    data_t data;

    data.envp = copy_table(envp);
    signal(SIGINT, handler1);
    initialize_history(&data);
    data.aliases = init_aliases();
    data.sets = init_sets();
    if (!data.envp || !data.history)
        return (84);
    while ((input = get_input()) != NULL) {
        if (mstrsame("\n", input) == false)
            fill_history(input, &data);
        if (split_parser(input, &data) == ERROR)
            return (ERROR);
        free(input);
    }
    marr_free(data.envp);
    return (0);
}
