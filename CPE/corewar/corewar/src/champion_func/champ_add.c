/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** champ_add
*/

#include <stdio.h>
#include "corewar.h"

int champ_add(champion_t *champion, char *map)
{
    mem_value_t *value = NULL;
    int type[3] = {T_REG | T_DIR | T_IND , T_REG | T_DIR | T_IND, T_REG};

    load_value(map, champion->pc + 1, &value, type);
    for (int i = 0 ; i < 3 ; i++)
        if (value[i].type == -1)
            return (ERROR);
    if (value[0].type == T_REG)
        value[0].value = champion->reg[value[0].value - 1];
    if (value[1].type == T_REG)
        value[1].value = champion->reg[value[1].value - 1];
    champion->reg[value[2].value] = value[0].value + value[1].value;
    champion->carry = 1;
    end_instruction(map, champion, value);
    return (SUCCESS);
}