/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** parse_rooms_two
*/

#include "lemin.h"
#include "struct.h"

void check_room_norme(char **array, int *status, parse_t *parse)
{
    if (my_str_isalphanum(array[0]) == 1 && my_getnbr(array[1]) >= 0
        && my_getnbr(array[2]) >= 0) {
        if (get_name_and_coord(array, parse) == 0) {
            *status = 84;
            return;
        }
        return;
    } else
        *status = 84;
    return;
}

int detect_start_end(char *str, parse_t *parse)
{
    int size = my_strlen(str);

    if (size >= 6 && str[0] == '#' && str[1] == '#' && str[2] == 'e' &&
        str[3] == 'n' && str[4] == 'd' && (str[5] == '\n'
        || str[5] == '\0')) {
        parse->st_start_end = 2;
        return (1);
    }
    if (size >= 8 && str[0] == '#' && str[1] == '#' && str[2] == 's'
        && str[3] == 't' && str[4] == 'a' && str[5] == 'r'
        && str[6] == 't' && (str[7] == '\n' || str[7] == '\0')) {
        parse->st_start_end = 1;
        return (1);
    }
    return (0);
}

int go_tunnel(parse_t *parse, int *status, char *str)
{
    if (parse->status != 11)
        return (0);
    *status = 3;
    my_putstr("#tunnels\n");
    check_tunnel(str, status, parse);
    return (1);
}