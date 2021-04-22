/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** exec_chamion
*/

#include <stdio.h>
#include <stdlib.h>
#include "corewar.h"

instruction_t command[] = {{0x01, champ_live}, {0x02, champ_ld},
    {0x03, champ_st}, {0x04, champ_add}, {0x05, champ_sub},
    {0x06, champ_and}, {0x07, champ_or}, {0x08, champ_xor},
    {0x09, champ_zjmp}, {0x0a, champ_ldi}, {0x0b, champ_sti},
    {0x0c, champ_fork}, {0x0d, champ_lld}, {0x0e, champ_lldi},
    {0x0f, champ_lfork}, {0x10, champ_aff}, {0xff, NULL}
};

int exec_current_champion(champion_t *champion, char *map)
{
    char temp = 0xff;

    for (int i = 0 ; command[i].mnemonic != temp ; i++) {
        if (command[i].mnemonic == map[champion->mem_index + champion->pc]) {
            return ((*command[i].func)(champion, map));
        }
    }
    return (SUCCESS);
}

int exec_champion(champion_t *champion, char *map)
{
    for (int i = 0 ; champion[i].filename ; i++) {
        if (champion[i].wait_time == 0 && champion[i].is_dead == 0 &&
            exec_current_champion(&champion[i], map) == ERROR)
            return (ERROR);
    }
    return (SUCCESS);
}