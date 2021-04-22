/*
** EPITECH PROJECT, 2019
** Tetris
** File description:
** Parse the file in the data struct
*/

#include <stdlib.h>
#include "tetris.h"
#include "data.h"
#include "mlib.h"

static int alloc_shape(data_t *data, int i)
{
    int size = sizeof(char *) * (data->tetriminos[i].height + 1);
    int row = 0;
    int col = 0;

    data->tetriminos[i].shape = malloc(size);
    if (!data->tetriminos[i].shape)
        return (ERROR);
    size = sizeof(char *) * (data->tetriminos[i].width + 1);
    for ( ; row < data->tetriminos[i].height ; row++) {
        data->tetriminos[i].shape[row] = malloc(size);
        if (!data->tetriminos[i].shape[row])
            return (ERROR);
    }
    for (row = 0 ; row < data->tetriminos[i].height ; row++) {
        for (col = 0 ; col < data->tetriminos[i].width ; col++)
            data->tetriminos[i].shape[row][col] = ' ';
        data->tetriminos[i].shape[row][col] = '\0';
    }
    data->tetriminos[i].shape[row] = NULL;
    return (SUCCESS);
}

static int tetrimino_cp(char *str, char *dest, int max)
{
    int row = 0;

    if (!str || !dest)
        return (ERROR);
    for ( ; row < max && str[row] ; row++)
        dest[row] = str[row];
    return (SUCCESS);
}

int tetrimino_parser(data_t *data, FILE *fp, int i)
{
    int max_col = data->tetriminos[i].width;
    int row = 0;
    char *buf = NULL;

    data->tetriminos[i].shape = NULL;
    if (alloc_shape(data, i) == ERROR)
        return (ERROR);
    while (row < data->tetriminos[i].height && (buf = mgetline(fp)))
        if (tetrimino_cp(buf, data->tetriminos[i].shape[row++], max_col))
            return (ERROR);
    data->tetriminos[i].shape[row] = NULL;
    if (!data->tetriminos[i].shape ||
        error_shape(data->tetriminos[i]) == true)
        return (ERROR);
    return (SUCCESS);
}

int name_parser(data_t *data, char *name, int i)
{
    int row = 0;

    data->tetriminos[i].name = mstr_cln(name);
    for ( ; data->tetriminos[i].name[row] ; row++);
    for ( ; data->tetriminos[i].name[row] != '.' && row > 0 ; row--);
    if (row < 0)
        return (ERROR);
    data->tetriminos[i].name[row] = '\0';
    return (SUCCESS);
}

int first_line_parser(data_t *data, FILE *fp, int i)
{
    char **arg = NULL;
    char *line = mgetline(fp);

    if (!line)
        return (ERROR);
    arg = marg(line);
    if (!arg || !arg[0] || !arg[1] || !arg[2])
        return (ERROR);
    if (mis_num(arg[0]) == 0
        || mis_num(arg[1]) == 0
        || mis_num(arg[2]) == 0)
        return (ERROR);
    data->tetriminos[i].width = mgetnbr(arg[0]);
    data->tetriminos[i].height = mgetnbr(arg[1]);
    data->tetriminos[i].color = mgetnbr(arg[2]);
    if (error_first_line(*data, data->tetriminos[i]) == true)
        return (ERROR);
    marg_free(arg);
    free(line);
    return (SUCCESS);
}
