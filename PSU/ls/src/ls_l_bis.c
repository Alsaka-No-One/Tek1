/*
** EPITECH PROJECT, 2019
** PSU my_ls | ls_bis
** File description:
** The second part of ls_l
*/

#include "ls.h"

void color_the_name(char *file, mode_t rt)
{
    if (rt & S_IFDIR)
        my_printf("\033[34m\033[1m%s\n\033[0m", file);
    else
        my_printf("%s\n", file);
}