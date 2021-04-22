/*
** EPITECH PROJECT, 2019
** Tetris
** File description:
** Alloc the tetriminos array
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "tetris.h"
#include "data.h"

static int count_tetriminos(data_t *data)
{
    int count = 0;
    DIR *dirp = opendir("tetriminos");
    struct dirent *file;

    if (!dirp)
        return (ERROR);
    while ((file = readdir(dirp)))
        if (file->d_type == DT_REG && is_tetrimino(file->d_name))
            count++;
    if (closedir(dirp) == -1)
        return (ERROR);
    data->nb_tetriminos = count;
    return (SUCCESS);
}

tetriminos_t *alloc_tetriminos(data_t *data)
{
    tetriminos_t *tetriminos;
    int size = sizeof(tetriminos_t);

    if (count_tetriminos(data) == ERROR)
        return (NULL);
    if (data->nb_tetriminos <= 0)
        return (NULL);
    size *= data->nb_tetriminos;
    tetriminos = malloc(size);
    if (!tetriminos)
        return (NULL);
    return (tetriminos);
}
