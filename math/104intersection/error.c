/*
** EPITECH PROJECT, 2018
** 104intersection_2018
** File description:
** error
*/

#include "intersection.h"

int check_number(char *str)
{
    for (int i = 0 ; str[i] != '\0' ; i += 1) {
        if ((str[i] > '9' || str[i] < '0') && str[i] != '-')
            return (84);
    }
    return (0);
}

int check_argument(int argc, char** argv)
{
    if (argc < 9)
        printf("Too few argument, use -h for more info\n");
    if (argc > 9)
        printf("Too many arguments, use -h for more info\n");
    for (int i = 1 ; i < argc ; i += 1) {
        if (check_number(argv[i]) == 84) {
            printf("Argument should only contain number, \"%s\" is not a number\n", argv[i]);
            return (84);
        }
    }
    return (0);
}