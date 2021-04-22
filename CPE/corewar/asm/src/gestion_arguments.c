/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** gestion_argument
*/

#include <unistd.h>
#include "asm.h"
#include "op.h"

int my_strcmp(char const *str1, char const *str2)
{
    int i = 0;

    if (!str1 && !str2)
        return (0);
    for ( ; str1[i] && str2[i] ; i++)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}

int move_iu(char const *str1, char const *str2, int *i, int *u)
{
    if (*u != 0 && (str2[(*u) - 1] == DIRECT_CHAR && str2[*u] == LABEL_CHAR)) {
        for (; ((str1[*i] >= '0' && str1[*i] <= '9') ||
            str1[*i] == '-'); (*i)++);
        (*i)--;
        (*u)++;
        for (; is_label(str2[*u]); (*u)++);
        (*u)--;
    }
    else
        return (0);
    return (1);
}

int cmp_l(char const *str1, char const *str2)
{
    int i = 0;
    int u = 0;
    int ret = 1;

    if (!str1 && !str2)
        return (0);
    for (; str1[i] && str2[u]; i++) {
        if (str1[i] != str2[u])
            (move_iu(str1, str2, &i, &u) == 0) ? ret = 0 : 0;
        if (ret == 0)
            return (0);
        u++;
    }
    return (1);
}

int assemble(int argc, char **argv)
{
    for (int i = 1 ; i < argc ; i++)
        if (label(argv[i]) == ERROR)
            return (ERROR);
    return (SUCCESS);
}

int gestion_arguments(int argc, char **argv)
{
    if (argc == 1) {
        write(1, "Usage: ./asm file_name[.s] ....\n", 32);
        return (ERROR);
    }
    if (my_strcmp(argv[1], "-h") == 1) {
        write(1, "Usage: ./asm file_name[.s] ....\n", 32);
        return (SUCCESS);
    }
    assemble(argc, argv);
    return (SUCCESS);
}