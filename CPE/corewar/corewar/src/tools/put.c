/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** mputerr
*/

#include <unistd.h>
#include "corewar.h"

void my_put(char const *str, int std)
{
    write(std, str, my_strlen(str));
}