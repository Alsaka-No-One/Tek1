/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** champ_live
*/

#include "corewar.h"

static int time_list[][2] = {{0x01, 10}, {0x02, 5}, {0x03, 5}, {0x04, 10},
    {0x05, 10}, {0x06, 6}, {0x07, 6}, {0x08, 6}, {0x09, 20}, {0x0a, 25},
    {0x0b, 25}, {0x0c, 800}, {0x0d, 10}, {0x0e, 50}, {0x0f, 1000},
    {0x10, 2}};

static void write_alive(champion_t *champion, int bytes)
{
    my_put("The player ", 1);
    mputnbr(bytes);
    my_put("(", 1);
    my_put(champion->name, 1);
    my_put(") is alive\n", 1);
}

int champ_live(champion_t *champion, char *map)
{
    int bytes = 0;

    bytes = bytes_to_int(map, champion->mem_index + champion->pc + 1, 4);
    write_alive(champion, bytes);
    champion->verif.alive = 1;
    champion->pc += 5;
    for (int i = 0 ; i < 17 ; i++) {
        if (map[champion->pc] == time_list[i][0]) {
            champion->wait_time = time_list[i][1];
            break;
        }
    }
    return (SUCCESS);
}