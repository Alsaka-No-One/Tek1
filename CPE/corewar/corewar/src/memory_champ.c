/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** memory_champ
*/

#include "corewar.h"

void memory_champ(char **argv, int i, champion_t *champion)
{
    int check = 0;

    if (my_strcmp(argv[i], "-a") == 1) {
        check = mgetnbr(argv[i + 1]);
        if (check > MEM_SIZE)
            champion->mem_index = check % MEM_SIZE;
        else
            champion->mem_index = check;
        champion->verif.is_memory = 1;
    }
}