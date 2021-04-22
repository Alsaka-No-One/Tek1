/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** instruction_end
*/

#include <stdlib.h>
#include "corewar.h"

static int time_list[][2] = {{0x01, 10}, {0x02, 5}, {0x03, 5}, {0x04, 10},
    {0x05, 10}, {0x06, 6}, {0x07, 6}, {0x08, 6}, {0x09, 20}, {0x0a, 25},
    {0x0b, 25}, {0x0c, 800}, {0x0d, 10}, {0x0e, 50}, {0x0f, 1000},
    {0x10, 2}};

void end_instruction(char *map, champion_t *champion, mem_value_t *value)
{
    champion->pc += 2;
    for (int i = 0 ; i < MAX_ARGS_NUMBER ; i++) {
        if (value[i].type == T_REG)
            champion->pc += T_REG;
        if (value[i].type == T_DIR)
            champion->pc += T_DIR;
        if (value[i].type == T_IND)
            champion->pc += T_IND;
        if (value[i].type == T_SHORTDIR)
            champion->pc += 2;
    }
    for (int i = 0 ; i < 17 ; i++) {
        if (map[champion->pc] == time_list[i][0]) {
            champion->wait_time = time_list[i][1];
            break;
        }
    }
    free(value);
}