/*
** EPITECH PROJECT, 2019
** PSU my_ls | check_arg
** File description:
** The function to check the argument
*/

#include "ls.h"

int option2(int argc, char **argv, int i, int *j)
{
    switch (argv[i][*j]) {
    case 'd':
        ls_d(argc, argv);
        *j += 1;
        option(argc, argv, i);
        *j = 1;
        break;
    case 'r':
        my_printf("-r flag");
        *j += 1;
        option(argc, argv, i);
        *j = 1;
        break;
    case 't':
        my_printf("-t flag");
        *j += 1;
        option(argc, argv, i);
        break;
    }
    return (0);
}

int option(int argc, char **argv, int i)
{
    static int j = 1;

    switch (argv[i][j]) {
    case 'R':
        recursivity();
        j += 1;
        option(argc, argv, i);
        j = 1;
        break;
    case 'l':
        ls_l();
        j += 1;
        option(argc, argv, i);
        j = 1;
        break;
    default:
        option2(argc, argv, i, &j);
        break;
    }
    return (0);
}

int disp(int argc, char **argv, int i)
{
    DIR *rep = NULL;
    struct dirent *rd = NULL;

    if ((rep = opendir(argv[i])) == NULL) {
        perror("error with opendir");
        exit(84);
    } else {
        if (argc != 2)
            my_printf("%s:\n", argv[i]);
        for (; (rd = readdir(rep)) != NULL; )
            (rd->d_name[0] != '.') ? my_printf("%s   ", rd->d_name) : 0;
        my_putchar('\n');
    }
    return (0);
}

int check_the_arg(int argc, char **argv)
{
    int i = 1;

    while (i <= argc - 1) {
        if (argv[i][0] == '-')
            return (1);
        i++;
    }
    return (0);
}