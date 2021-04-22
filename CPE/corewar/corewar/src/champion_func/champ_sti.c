/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** champ_sti
*/

#include <stdlib.h>
#include "corewar.h"

int champ_sti(champion_t *champion, char *map)
{
    mem_value_t *value = NULL;
    int type[3] = {T_REG , T_REG | T_SHORTDIR, T_REG | T_SHORTDIR};
    int index = 0;

    load_value(map, champion->pc + 1, &value, type);
    for (int i = 0 ; i < 3 ; i++)
        if (value[i].type == -1)
            return (ERROR);
    index += value[1].type == T_REG ? champion->reg[value[1].value] :
        value[1].value;
    index += value[2].type == T_REG ? champion->reg[value[2].value] :
        value[2].value;
    index %= IDX_MOD;
    print_in_mem(map, champion->mem_index + index, -1,
        champion->reg[value[0].value - 1]);
    end_instruction(map, champion, value);
    return (SUCCESS);
}