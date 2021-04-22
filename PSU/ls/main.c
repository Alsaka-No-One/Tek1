/*
** EPITECH PROJECT, 2019
** PSU my_ls | main
** File description:
** The main function
*/

#include "ls.h"

int mini_ls(void)
{
    DIR *rep = NULL;
    struct dirent *rd = NULL;

    if ((rep = opendir("./")) == NULL)
        return (84);
    else 
        while ((rd = readdir(rep)) != NULL)
            (rd->d_name[0] != '.') ? my_printf("%s   ", rd->d_name) : 0;
    return (0);
}

int mini_ls_main(int argc, char **argv)
{
    int i = 1;

    if (check_the_arg(argc, argv) == 0)
        while (i <= argc - 1) {
            disp(argc, argv, i);
            i++;
        }
    else
        while (i <= argc - 1) {
            option(argc, argv, i);
            i++;
        }
    return (0);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        mini_ls();
    else if (argc >= 2)
        mini_ls_main(argc, argv);
    return (0);
}
