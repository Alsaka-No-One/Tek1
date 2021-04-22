/*
** EPITECH PROJECT, 2019
** duo_stumper 2
** File description:
** boggle
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

int check_string(char *str, char *str2, char **argv)
{
    if (error_size_map(argv[2]) == ERROR) {
        write(2, "Invalid number of letters for the grill\n", 40);
        return (ERROR);
    }
    if (find_str(str, str2) == 1) {
        return (display_win(str, str2));
    }
    else if (find_str(str, str2) == -1) {
        printf("The word “%s” is not in the grid.\n", str);
        return (ERROR);
    }
    return (0);
}

int boggle(int ac, char **av)
{
    if (ac == 5 && av[3][0] == '-' && av[3][1] == 'w')
        return (check_string(av[4], av[2], av));
    if (ac == 7 && av[5][0] == '-' && av[5][1] == 's')
        //return (size_of_grid(av));
        return (0);
    return (0);
}
