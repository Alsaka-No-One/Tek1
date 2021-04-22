/*
** EPITECH PROJECT, 2019
** CPE matchstick | main
** File description:
** The main function
*/

#include "stick.h"
#include "function.h"

void print_map(int height, char **map)
{
    for (int i = 0; i < height + 2; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
    my_putchar('\n');
}

int matchstick_main(char **argv)
{
    int nb_line = my_getnbr(argv[1]);
    int max_delete = my_getnbr(argv[2]);
    char **map = NULL;
    int try = 0;

    if (nb_line <= 1 || nb_line >= 100) {
        write(2, "Invalid size of map! 1 < n < 100\n", 33);
        return (84);
    }
    if (max_delete <= 0) {
        write(2, "You must remove at least 1 stick\n", 33);
        return (84);
    }
    map = fill_the_map(nb_line);
    try = game_loop(nb_line, max_delete, map);
    if (try == 1)
        return (1);
    if (try == 3)
        return (0);
    my_putstr("You lost, too bad...\n");
    return (2);
}

int main(int argc, char **argv)
{
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        display_usage();
        return (0);
    }
    if (argc != 3) {
        write(2, "Invalid argument, try -h for more info!\n", 40);
        return (84);
    }
    else 
        return (matchstick_main(argv));
}
