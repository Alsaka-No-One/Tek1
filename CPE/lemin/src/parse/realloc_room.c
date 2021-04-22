/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** realloc_room
*/

#include "lemin.h"
#include "struct.h"

//JE NE VERIFI PAS LES MALLOC !!!!
//Maintenant Si!!!!!

room_t *realloc_rooms(room_t *parse, int size)
{
    room_t *new = malloc(sizeof(room_t) * (size + 2));

    VERIF_MALLOC(new);
    for (int i = 0; i < size + 1; i++) {
        if (parse[i].name != NULL) {
            new[i].name =
                malloc(sizeof(char) * (my_strlen(parse[i].name) + 1));
            VERIF_MALLOC(new[i].name);
            new[i].name = my_getstr(parse[i].name);
            new[i].x = parse[i].x;
            new[i].y = parse[i].y;
            new[i].status = parse[i].status;
        }
    }
    new[size].name = NULL;
    new[size + 1].name = NULL;
    for (int i = 0; parse[i].name != NULL; i++)
        free(parse[i].name);
    free(parse);
    return (new);
}

int get_room(parse_t *parse, char **array)
{
    int size = 0;
    room_t *new;

    while (parse->rooms[size].name != NULL)
        size++;
    new = realloc_rooms(parse->rooms, size);
    if ((parse->rooms = realloc_rooms(new, size)) == NULL)
        return (-1);
    if ((parse->rooms[size].name = my_getstr(array[0])) == NULL)
        return (-1);
    if (parse->rooms[size].name == NULL)
        return (-1);
    parse->rooms[size].x = my_getnbr(array[1]);
    parse->rooms[size].y = my_getnbr(array[2]);
    return (size);
}
