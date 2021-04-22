/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** parse_rooms
*/

#include "lemin.h"
#include "struct.h"

int check_name_coord(char *str, int x, int y, parse_t *parse)
{
    for (int i = 0; parse->rooms[i + 1].name != NULL; i++) {
        if (my_strcomp(str, parse->rooms[i].name) == 1)
            return (0);
        if (parse->rooms[i].x == x && parse->rooms[i].y == y)
            return (0);
    }
    return (1);
}

void display_room(parse_t *parse, int size)
{
    if (parse->rooms[size].status == 1)
        my_putstr("##start\n");
    else if (parse->rooms[size].status == 2)
        my_putstr("##end\n");
    my_putstr(parse->rooms[size].name);
    my_putstr(" ");
    my_put_nbr(parse->rooms[size].x);
    my_putstr(" ");
    my_put_nbr(parse->rooms[size].y);
    my_putstr("\n");
}

int get_name_and_coord(char **array, parse_t *parse)
{
    int size = get_room(parse, array);

    if (size == -1)
        return (0);
    if (parse->st_start_end == 1) {
        parse->rooms[size].status = 1;
        parse->st_start_end = 0;
        parse->status += 1;
    } else if (parse->st_start_end == 2) {
        parse->rooms[size].status = 2;
        parse->st_start_end = 0;
        parse->status += 10;
    } else
        parse->rooms[size].status = 0;
    if (check_name_coord(parse->rooms[size].name, parse->rooms[size].x
        , parse->rooms[size].y, parse) == 0)
        return (0);
    display_room(parse, size);
    return (1);
}

void check_room(char *str, int *status, parse_t *parse)
{
    char **array = NULL;

    if (detect_start_end(str, parse) == 1)
        return;
    if (com_or_not(str) == 1)
        return;
    if ((array = get_arg_str(str, array)) == NULL) {
        *status = 84;
        return;
    } if (double_tab_len(array) != 3) {
        if (go_tunnel(parse, status, str) == 0) {
            *status = 84;
            free_array(array);
            return;
        }
        free_array(array);
        return;
    }
    check_room_norme(array, status, parse);
    free_array(array);
}