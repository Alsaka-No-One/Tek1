/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** vm
*/

#include <stddef.h>
#include <stdio.h>
#include "unistd.h"
#include <stdlib.h>
#include "corewar.h"

static void write_winner(data_t *data)
{
    my_put("The player ", 1);
    mputnbr(data->last_live);
    my_put("(", 1);
    if (data->last_name != NULL)
    my_put(data->last_name, 1);
    my_put(") has won\n", 1);
}

static void last_alive(data_t *data)
{
    int change = 0;

    for (int i = 0 ; data->champion[i].filename ; i++) {
        if (data->champion[i].verif.alive == 1 && change == 0 &&
            data->champion[i].is_dead == 0) {
            data->last_live = data->champion[i].nb_player;
            data->last_name = data->champion[i].name;
            change = 1;
        } else if (data->champion[i].verif.alive == 0)
            data->champion[i].is_dead = 1;
        data->champion[i].verif.alive = 0;
    }
}

static int loop_vm(data_t *data, char *map)
{
    static int cycle_die = 0;
    static int count = 0;

    exec_champion(data->champion, map);
    for (int i = 0 ; data->champion[i].filename ; i++)
        (data->champion[i].wait_time)--;
    if (cycle_die == data->time_cycle_die) {
        cycle_die = 0;
        last_alive(data);
        if (count == NBR_LIVE) {
            count = 0;
            data->time_cycle_die -= CYCLE_DELTA;
        }
        count++;
    } else if (data->time_cycle_die <= 0)
        return (ERROR);
    cycle_die++;
    return (SUCCESS);
}

int vm(data_t *data)
{
    char *map = create_map();

    if (map == NULL)
        return (ERROR);
    if (load_champion(data->champion) == ERROR) {
        free(map);
        return (ERROR);
    }
    place_champion(map, data->champion);
    for (int i = 0 ; 1 ; i++) {
        if (loop_vm(data, map) == ERROR)
            break;
        if (i == data->dump && data->dump != 0) {
            dump_memory(map);
            break;
        }
    }
    if (data->dump == 0)
        write_winner(data);
    free(map);
    return (SUCCESS);
}