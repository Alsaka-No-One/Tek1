/*
** EPITECH PROJECT, 2018
** BSQ | open file
** File description:
** A function that open a file
*/

#include "../include/bsq.h"

int fs_open_file(char const *filepath)
{
    int fd;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        error_open();
        exit(84);
    }
    return (fd);
}

char *fs_print_file(char const *filepath, char *buffer)
{
    int fd = fs_open_file(filepath);
    struct stat sb;

    if (stat(filepath, &sb) == -1)
        exit(84);
    else {
        buffer = malloc(sizeof(char) * sb.st_size + 2);
        if (buffer == NULL)
            exit(84);
        if (sb.st_size == 0)
            exit(84);
        read(fd, buffer, sb.st_size);
    }
    buffer[sb.st_size] = '\0';
    return (buffer);
}
