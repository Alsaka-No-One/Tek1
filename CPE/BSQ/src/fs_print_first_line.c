/*
** EPITECH PROJECT, 2018
** Alsaka | Boostrap BSQ | fs_print_first_line
** File description:
** A function that display the first line of a file
*/

#include "../include/bsq.h"

void fs_print_first_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[101];
    int i = 0;

    if (fd == -1) {
        my_putstr("FAILURE");
        return;
    }
    while (read(fd, buffer, 100)) {
        for (i = 0; buffer[i] != '\n' && i < 100; i++) {
            my_putchar(buffer[i]);
        }
        if (buffer[i] == '\n')
            break;
    }
    close(fd);
}
