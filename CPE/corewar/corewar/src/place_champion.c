/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** place_champion
*/

#include "op.h"
#include "corewar.h"

static void place_on_map(char *map, int index, champion_t champion)
{
    for (int i = 0 ; i < champion.code_size ; i++)
        map[index + i] = champion.code[i];
}

int place_champion(char *map, champion_t *champion)
{
    int nb_champion = 0;
    int index = 0;
    int pas = 0;

    for ( ; champion[nb_champion].filename ; nb_champion++);
    pas = MEM_SIZE / nb_champion;
    for (int i = 0 ; i < nb_champion ; i++) {
        place_on_map(map, index, champion[i]);
        champion[i].mem_index = index;
        index += pas;
    }
    return (SUCCESS);
}