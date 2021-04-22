/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** parse_file
*/

#include "lemin.h"
#include "struct.h"

static int initialize_parse(parse_t *parse)
{
    parse->rooms = malloc(sizeof(room_t) * 2);
    VERIF_INT_MALLOC(parse->rooms);
    parse->rooms[0].name = NULL;
    parse->rooms[1].name = NULL;
    if ((parse->tunnel = malloc(sizeof(char *) * 2)) == NULL)
        return (ERROR);
    parse->tunnel[0] = NULL;
    parse->tunnel[1] = NULL;
    parse->status = 0;
    parse->st_start_end = 0;
    my_putstr("#number_of_ants\n");
    return (SUCCESS);
}

static int end_parse(int status, char *str, parse_t *parse)
{
    if (status == 1)
        return (84);
    free(str);
    my_putstr("#moves\n");
    if (parse->tunnel[0] == NULL)
        return (84);
    return (graph(parse));
}

int handling_error(int *status, char *str)
{
    if (*status == 84) {
        free(str);
        return (1);
    }
    return (0);
}   

int parse_file(void)
{
    char *str = NULL;
    parse_t parse;
    size_t size = 0;
    int status = 1;

    if (initialize_parse(&parse) == ERROR) {
        my_putstr("Error with malloc\n");
        return (ERROR);
    }
    for (int i = 0; getline(&str, &size, stdin) != -1 && status != 83; i++) {
        if (status == 3)
            check_tunnel(str, &status, &parse);
        if (status == 2)
            check_room(str, &status, &parse);
        if (status == 1)
            find_nb_ants(str, &status, &parse);
        if (handling_error(&status, str) == 1)
            return (ERROR);
    }
    return (end_parse(status, str, &parse));
}
