/*
** EPITECH PROJECT, 2019
** Solo stumper 1 | main
** File description:
** The main function
*/

#include "stumper.h"

int sort_main(char *argv)
{
    char *words = NULL;

    words = regroup_words(argv);
    my_printf("%s\n", words);
    words = swap(words);
    my_printf("%s\n", words);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc > 2)
        return (84);
    else if (argc == 1) {
        my_putchar('\n');
        return (0);
    }
    if (argc == 2) {
        sort_main(argv[1]);
        return (0);
    }
}
