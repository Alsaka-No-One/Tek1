/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** env function
*/

#include <unistd.h>
#include "minishell.h"
#include "mlib.h"

int my_env(data_t *data, char **input)
{
    if (!data->envp)
        return (ERROR);
    if (mrow(input) != 1)
        return (ERROR);
    for (int i = 0 ; (data->envp)[i] ; i++) {
        mputstr((data->envp)[i]);
        mputchar('\n');
    }
    return (SUCCESS);
}
