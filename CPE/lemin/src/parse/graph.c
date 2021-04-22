/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** graph
*/

#include "lemin.h"
#include "struct.h"

int str_str(char *str1, char *str2)
{
    for (int nb = 0; str1[nb] == str2[nb]; nb++) {
        if (str1[nb] == '\0' && str2[nb] == '\0')
            return (1);
    }
    return (0);
}

int graph_tree(parse_t *parse, char *room1, char *room2)
{
    int room1_emp = 0;
    int room2_emp = 0;

    while (str_str(parse->rooms[room1_emp].name, room1) != 1)
        room1_emp++;
    while (str_str(parse->rooms[room2_emp].name, room2) != 1)
        room2_emp++;
    parse->rooms[room1_emp].tun[parse->rooms[room1_emp].nbr_tun]
        = &parse->rooms[room2_emp];
    parse->rooms[room1_emp].nbr_tun++;
    parse->rooms[room2_emp].tun[parse->rooms[room2_emp].nbr_tun]
        = &parse->rooms[room1_emp];
    parse->rooms[room2_emp].nbr_tun++;
}

int graph_two(parse_t *parse, int compt, char *room1, char *room2)
{
    int con;
    int emp;

    room1 = malloc(sizeof(parse->tunnel[compt]));
    room2 = malloc(sizeof(parse->tunnel[compt]));
    if (room1 == NULL || room2 == NULL)
        return (ERROR);
    for (con = 0; parse->tunnel[compt][con] != '-'; con++)
        room1[con] = parse->tunnel[compt][con];
    room1[con] = '\0';
    con++;
    for (emp = 0; parse->tunnel[compt][con] != '\0'; con++) {
        room2[emp] = parse->tunnel[compt][con];
        emp++;
    }
    room2[emp] = '\0';
    return (graph_tree(parse, room1, room2));
}

int tunnel_start_room(parse_t *parse)
{
    int i = 0;

    while (parse->rooms[i].status != 1)
        i++;
    if (parse->rooms[i].tun == NULL || parse->rooms[i].tun[0] == NULL)
        return (84);
    return (0);
}

int graph(parse_t *parse)
{
    char *room1;
    char *room2;

    for (int mal = 0; parse->rooms[mal].name != NULL; mal++) {
        parse->rooms[mal].tun = malloc(sizeof(parse->rooms[mal]) + 1);
        if (parse->rooms[mal].tun == NULL)
            return (84);
        parse->rooms[mal].nbr_tun = 0;
    }
    for (int compt = 0; parse->tunnel[compt] != NULL; compt++)
        if (graph_two(parse, compt, room1, room2) == ERROR)
            return (ERROR);
    if (tunnel_start_room(parse) == 84 || algo(parse) == 84)
        return (84);
    for (int jhh = 0; parse->rooms[jhh].name != NULL; jhh++)
        free(parse->rooms[jhh].tun);
    return (SUCCESS);
}
