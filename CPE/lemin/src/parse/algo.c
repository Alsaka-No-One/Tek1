/*
** EPITECH PROJECT, 2019
** algo
** File description:
** an algorithm
*/

#include "lemin.h"

int algo_tree(parse_t *parse)
{
    int back = 0;

    parse->rooms[parse->room].tunn++;
    parse->tunn = parse->rooms[parse->room].tunn;
    back = 1;
    while (back != 0) {
        if (parse->rooms[parse->room].tun[parse->tunn] == NULL) {
            parse->save_way--;
            if (parse->room == parse->start)
                return (ERROR);
            parse->room = parse->way[parse->save_way - 1];
        }
        else
            back = 0;
    }
}

int algo_four(parse_t *parse)
{
    while (parse->rooms[parse->room].tun[parse->tunn]->status != 2) {
        if (parse->save_way != 0
            && parse->rooms[parse->room].tun[parse->tunn]->pos
            == parse->way[parse->save_way - 1]) {
            parse->last = 0;
        }
        else {
            parse->way[parse->save_way] = parse->rooms[parse->room].pos;
            parse->room = parse->rooms[parse->room].tun[parse->tunn]->pos;
            parse->save_way++;
            parse->last = 1;
        }
        if (algo_tree(parse) == 84)
            return (ERROR);
    }
}

int algo_two(parse_t *parse)
{
    parse->last = 0;
    parse->room = 0;
    parse->tunn = 0;
    parse->save_way = 0;
    parse->room = parse->start;
    parse->way[parse->save_way]
        = parse->rooms[parse->room].tun[parse->tunn]->pos;
    if (algo_four(parse) == 84)
        return (ERROR);
    if (parse->last == 0)
        parse->way[parse->save_way] = parse->rooms[parse->room].pos;
    parse->way[parse->save_way + 1]
        = parse->rooms[parse->room].tun[parse->tunn]->pos;
    parse->way[parse->save_way + 2] = -1;
}

int algo(parse_t *parse)
{
    parse->way = malloc(sizeof(int) * sizeof(parse->rooms));
    if (parse->way == NULL)
        return (ERROR);
    for (int mal = 0; parse->rooms[mal].name != NULL; mal++) {
        parse->rooms[mal].ant = 0;
        parse->rooms[mal].pos = mal;
        parse->rooms[mal].tunn = -1;
        if (parse->rooms[mal].status == 1) {
            parse->rooms[mal].ant = parse->nb_ants;
            parse->start = mal;
        }
    }
    if (algo_two(parse) == 84)
        return (ERROR);
    disp_moves(parse);
    free(parse->way);
}
