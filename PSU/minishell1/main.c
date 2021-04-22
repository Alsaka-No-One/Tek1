/*
** EPITECH PROJECT, 2019
** PSU minishell 1 | main
** File description:
** The main function
*/

#include "function.h"
#include "shell.h"

int minishell_main(char **envp)
{
    size_t n = 0;
    char *buff = NULL;
    char **new_env = NULL;
    char **arg = NULL;
    int i = 0;

    my_putstr("$> ");
    new_env = remalloc(envp);
    while (getline(&buff, &n, stdin) != -1) {
        arg = string_to_arg(buff);
        if (str_comp(arg[0], "env") != -1)
            new_env = print_env(new_env, arg);
        else if (str_comp(arg[0], "setenv") != -1)
            new_env = set_env(new_env, arg);
        else if (str_comp(arg[0], "exit") != -1) {
            i = my_exit(arg);
            return (i);
        }
        else {
            buff[my_strlen(buff) - 1] = '\0';
            my_putstr(buff);
            my_putstr(": Command not found.\n");
        }
        my_putstr("$> ");
        destroy_arg(arg);
    }
    my_putstr("exit\n");
    return (0);
}

int main(int argc, char **argv, char **envp)
{
    (void)argv;
    if (argc != 1)
        return (84);
    return (minishell_main(envp));
}