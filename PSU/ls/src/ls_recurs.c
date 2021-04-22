/*
** EPITECH PROJECT, 2019
** PSU my_ls | resursion
** File description:
** The -R function
*/

#include "ls.h"

void display_ls(char *filepath)
{
    DIR *rep = NULL;
    struct dirent *rd = NULL;

    if ((rep = opendir(filepath)) == NULL) {
        perror("error with opendir");
        exit(84);
    } else {
        while ((rd = readdir(rep)) != NULL)
            (rd->d_name[0] != '.') ? my_printf("%s   ", rd->d_name) : 0;
    }
}

void recursivity(void)
{
    display_ls("./");
}