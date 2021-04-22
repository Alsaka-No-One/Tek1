/*
** EPITECH PROJECT, 2019
** Tetris
** File description:
** Main function
*/

#include "tetris.h"
#include "data.h"

int tetris(int ac, char **av)
{
    data_t data = load_data();

    option(ac, av, &data);
    if (data_verif(data))
        return (ERROR);
    if (load_tetriminos(&data) == ERROR)
        return (ERROR);
    if (data.debug == true)
        print_debug(data);
    if (gameloop(&data) == ERROR)
        return (ERROR);
    return (SUCCESS);
}
