/*
** EPITECH PROJECT, 2019
** stumper
** File description:
** error_gestion
*/

#include "stumper.h"

static int check_number(char *number)
{
    int i = 0;

    while (number[i] != '\0') {
        if (number[i] < '0' || number[i] > '9') {
            write(2, "Invalid charact in the number!\n", 31);
            return (84);
        }
        i++;
    }
    return (0);
}

static int check_argument(int argc, char **argv)
{
    int i = 1;
    int status = 0;

    while (i != argc) {
        if (argv[i][0] == '-' && argv[i][1] == 'n')
            status += 1;
        i++;
    }
    if (status != 1) {
        write(2, "Problem with -n!\n", 17);
        return (84);
    }
    return (0);
}

static int check_string(int argc, char **argv)
{
    int i = 1;
    int status = 0;

    while (i != argc) {
        if (argv[i][0] == '-' && argv[i][1] == 's') {
            status += 1;
            break;
        }
        i++;
    }
    if (status == 0)
        return (0);
    else if (status != 1)
        return (84);
    if (argv[i + 1] == NULL)
        return (84);
    return (0);
}

int error_gestion(int argc, char **argv)
{
    int i = 1;
    int status = 0;

    if (argc != 3 && argc != 5) {
        write(2, "Invalid number of argument\n", 27);
        return (84);
    }
    if (check_argument(argc, argv) == 84)
        return (84);
    for (; i != argc; i++)
        if (argv[i][0] == '-' && argv[i][1] == 'n') {
            status = check_number(argv[i + 1]);
            break;
        }
    if (check_string(argc, argv) == 84)
        return (84);
    if (i == argc || status == 84)
        return (84);
    return (crocus(argv));
}
