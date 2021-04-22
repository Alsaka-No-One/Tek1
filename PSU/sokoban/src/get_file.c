/*
** EPITECH PROJECT, 2018
** BSQ | open file
** File description:
** A function that open a file
*/

#include "../include/sokoban.h"

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
        buffer = malloc(sizeof(char) * (sb.st_size + 2));
        if (buffer == NULL)
            exit(84);
        if (sb.st_size == 0)
            exit(84);
        read(fd, buffer, sb.st_size);
    }
    buffer[sb.st_size] = '\0';
    return (buffer);
}

int get_linum(char *buffer)
{
    int i = 0;
    int linum = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            linum++;
        i++;
    }
    linum++;
    return (linum);
}

int get_cols_max(char *buffer)
{
    int i = 0;
    int cols = 0;
    int j = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            (j > cols) ? cols = j : 0;
            j = -1;
        }
        j++;
        i++;
    }
    return (cols);
}

char **get_tab(char *src, char **dest, coord_t *coord)
{
    int linum = 0;
    int cols = 0;
    int count = 0;

    dest = malloc(sizeof(char *) * (coord->linum * (coord->cols + 2)));
    for (int j = 0; j < coord->linum + 1; j++) {
        dest[j] = malloc(sizeof(char) * (coord->cols + 2));
        dest[j][coord->cols] = '\0';
    }
    while (src[count] != '\0') {
        if (src[count] == '\n') {
            cols = 0;
            linum++;
            count++;
        }
        dest[linum][cols] = src[count];
        cols++;
        count++;
    }
    return (dest);
}
