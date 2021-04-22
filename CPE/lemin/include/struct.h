/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct room_s
{
    char *name;
    int x;
    int y;
    int status;
    struct room_s **tun;
    int nbr_tun;
    int ant;
    int pos;
    int tunn;
} room_t;

typedef struct ant_s
{
    int pos;
    int way;
    int status;
} ant_t;

typedef struct parse_s
{
    int nb_ants;
    ant_t *ants;
    room_t *rooms;
    char **tunnel;
    int status;
    int st_start_end;
    int start;
    int *way;
    int room;
    int tunn;
    int save_way;
    int last;
} parse_t;

#endif
