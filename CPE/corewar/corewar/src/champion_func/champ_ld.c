/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** champ_ld
*/

#include <stdlib.h>
#include "corewar.h"

int champ_ld(champion_t *champion, char *map)
{
    mem_value_t *value = NULL;
    int type[4] = {T_REG | T_DIR, T_REG, 0, 0};
    int temp = 0;

    load_value(map, champion->pc + 1, &value, type);
    for (int i = 0 ; i < 2 ; i++)
        if (value[i].type == -1)
            return (ERROR);
    temp = bytes_to_int(map, champion->pc + (value[0].value % IDX_MOD),
        REG_SIZE);
    champion->reg[value[1].value - 1] = temp;
    end_instruction(map, champion, value);
    return (SUCCESS);
}