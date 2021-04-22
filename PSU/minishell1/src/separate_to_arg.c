/*
** EPITECH PROJECT, 2019
** PSU minishell 1 | separate to arg
** File description:
** The function to separate to arg
*/

#include "function.h"
#include "shell.h"

char **destroy_arg(char **arg)
{
    int i = 0;

    while (arg[i])
        i++;
    i--;
    while (i != 0) {
        free(arg[i]);
        arg[i] = '\0';
        i--;
    }
    return (arg);
}

static int whitespace_dodge(char *buff, int i)
{
    while (buff[i] == ' ' && buff[i] != '\0')
        i++;
    return (i);
}

static int count_in_buff(char *buff)
{
    int i = 0;
    int j = 0;

    if (buff[0] == ' ')
        j = whitespace_dodge(buff, j);
    while (buff[j] != '\0') {
        if (buff[j] == ' ' || buff[j] == '\n') {
            i += 1;
            (buff[j + 1] == ' ') ? j = whitespace_dodge(buff, j) : 0;
        }
        j++;
    }
    return (i + 5);
}

static char **mal_tab(char **tab, char *buff)
{
    if ((tab = malloc(sizeof(char *) * count_in_buff(buff))) == NULL)
        return (NULL);
    for (int i = 0; i != count_in_buff(buff); i++)
        if ((tab[i] = malloc(sizeof(char) * my_strlen(buff))) == NULL)
            return (NULL);
    return (tab);
}

char **string_to_arg(char *buff)
{
    char **arg = NULL;
    int i_tab = 0;
    int j_tab = 0;
    int j = 0;

    arg = mal_tab(arg, buff);
    if (buff[0] == ' ')
        j = whitespace_dodge(buff, j);
    while (buff[j] != '\0') {
        if (buff[j] == ' ' || buff[j] == '\n') {
            arg[i_tab][j_tab] = '\0';
            (buff[j + 1] == ' ') ? j = whitespace_dodge(buff, j) : 0;
            j++;
            i_tab += 1;
            j_tab = 0;
        }
        arg[i_tab][j_tab] = buff[j];
        j++;
        j_tab++;
    }
    arg[i_tab] = NULL;
    return (arg);
}