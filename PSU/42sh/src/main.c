/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** main
*/

#include <stdlib.h>
#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    if (envp[0] == NULL) {
        mputerror("Please check your environement\n");
        return (ERROR);
    }
    return (minishell(envp));
}