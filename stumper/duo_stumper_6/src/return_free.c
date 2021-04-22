/*
** EPITECH PROJECT, 2019
** duostumper
** File description:
** 
*/

#include <stdlib.h>
#include "stumper.h"

int return_free(char *str)
{
    free(str);
    return (SUCCESS);
}
