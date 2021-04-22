/*
** EPITECH PROJECT, 2019
** Tetris
** File description:
** Open and read to fill the tetriminos struct, parsing is in data_parser.c
*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include "tetris.h"
#include "data.h"
#include "mlib.h"

static void read_tetrimino(data_t *data, struct dirent *file, FILE *fp)
{
    static int i = -1;

    data->tetriminos[++i].error = false;
    if (name_parser(data, file->d_name, i) == ERROR) {
        data->tetriminos[i].error = true;
        return;
    }
    if (first_line_parser(data, fp, i) == ERROR) {
        data->tetriminos[i].error = true;
        return;
    }
    if (tetrimino_parser(data, fp, i) == ERROR) {
        data->tetriminos[i].error = true;
        return;
    }
}

static int load_tetrimino(data_t *data, struct dirent *file)
{
    FILE *fp = NULL;

    if (file->d_type == DT_REG && is_tetrimino(file->d_name)) {
        if (open_tetrimino(&fp, file->d_name))
            return (ERROR);
        read_tetrimino(data, file, fp);
        if (fclose(fp) == -1)
            return (ERROR);
    }
    return (SUCCESS);
}

int fill_tetriminos(data_t *data)
{
    DIR *dirp = opendir("tetriminos");
    struct dirent *file;

    if (!dirp)
        return (ERROR);
    while ((file = readdir(dirp)))
        if (load_tetrimino(data, file) == ERROR)
            return (ERROR);
    if (closedir(dirp) == -1)
        return (ERROR);
    return (SUCCESS);
}
