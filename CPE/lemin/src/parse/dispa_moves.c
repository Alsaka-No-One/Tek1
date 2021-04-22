/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** dispa_moves
*/

#include "lemin.h"

int initialize_ants(parse_t *parse)
{
    parse->ants = malloc(sizeof(ant_t) * (parse->nb_ants + 1));
    if (parse->ants == NULL)
        return (0);
    for (int i = 0; i < parse->nb_ants; i++) {
        parse->ants[i].way = 1;
        parse->ants[i].pos = parse->way[1];
        parse->ants[i].status = 0;
    }
    return (1);
}

int check_end_disp(parse_t *parse)
{
    int status = 0;

    for (int k = 0; k < parse->nb_ants; k++)
        if (parse->ants[k].status == 0 || parse->ants[k].status == 1)
            status++;
    if (status != 0)
        return (0);
    return (1);
}

void disp_one_move(parse_t *parse, int *i)
{
    my_putstr("P");
    my_put_nbr(*i + 1);
    my_putstr("-");
    my_putstr(parse->rooms[parse->ants[*i].pos].name);
}

void display_move_ants(parse_t *parse, int *k, int *i)
{
    if (parse->ants[*i].status == 0) {
        disp_one_move(parse, i);
        parse->ants[*i].way++;
        if (parse->way[parse->ants[*i].way] == -1) {
            parse->ants[*i].status = 2;
            return;
        }
        parse->ants[*i].pos = parse->way[parse->ants[*i].way];
        if (parse->rooms[parse->ants[*i].pos].status == 2)
            parse->ants[*i].status = 1;
        if (*i + 1 < parse->nb_ants && *i + 1 < *k)
            my_putstr(" ");
    } else if (parse->ants[*i].status == 1) {
        disp_one_move(parse, i);
        parse->ants[*i].status = 2;
        if (*i + 1 < parse->nb_ants && *i + 1 < *k)
            my_putstr(" ");
    }
}

int disp_moves(parse_t *parse)
{
    int status = 0;
    int k = 1;

    if (initialize_ants(parse) == 0)
        return (84);
    while (status == 0) {
        for (int i = 0; i < parse->nb_ants && i < k; i++)
            display_move_ants(parse, &k, &i);
        if (check_end_disp(parse) == 1)
            status = 1;
        k++;
        if (parse->nb_ants != 0)
            my_putstr("\n");
    }
    return (0);
}