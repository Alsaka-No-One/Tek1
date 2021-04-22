/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** minishell
*/

#include "shell.h"

static int end_prog(char *buff, char **env)
{
    my_putstr("exit\n");
    free(buff);
    free_tab(env);
    return (SUCCESS);
}

int minishell(char **envp)
{
    size_t n = 0;
    char *buff = NULL;
    char **arg = NULL;
    char **env = NULL;
    func_t tab[4] = {{&make_cd, "cd"}, {&make_setenv, "setenv"}
                    , {&make_unsetenv, "unsetenv"}, {&make_env, "env"}};

    my_putstr("$> ");
    env = get_env(envp);
    while (getline(&buff, &n, stdin) != -1) {
        arg = string_to_arg(buff);
        if (my_strcomp(arg[0], "exit") == 1)
            return (my_exit(arg));
        if (get_command(tab, arg, &env) == ERROR)
            return (ERROR);
        free_tab(arg);
        my_putstr("$> ");
    }
    return (end_prog(buff, env));
}