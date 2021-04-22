/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** champ_st
*/

#include <stdlib.h>
#include "corewar.h"

int champ_st(champion_t *champion, char *map)
{
    mem_value_t *value = NULL;
    int type[3] = {T_REG , T_REG | T_SHORTDIR};
    int index = 0;

    load_value(map, champion->pc + 1, &value, type);
    for (int i = 0 ; i < 2 ; i++)
        if (value[i].type == -1)
            return (ERROR);
    if (value[1].type == T_REG) {
        champion->reg[value[1].value - 1] = champion->reg[value[0].value - 1];
    } else {
        index = value[1].value;
        index %= IDX_MOD;
        print_in_mem(map, champion->mem_index + index, -1,
            champion->reg[value[0].value - 1]);
    }
    end_instruction(map, champion, value);
    return (SUCCESS);
}