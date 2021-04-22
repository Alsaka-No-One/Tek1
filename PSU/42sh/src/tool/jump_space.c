/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** jump_space
*/

#include "minishell.h"

int jump_space(char *str, int start)
{
    for ( ; str[start] == ' ' && str[start] == '\t'
    && str[start] != '\0' ; start++);
    return (start);
}