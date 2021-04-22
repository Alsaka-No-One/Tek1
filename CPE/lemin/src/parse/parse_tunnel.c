/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** parse_tunnel
*/

#include "lemin.h"
#include "struct.h"

int check_name(char *name, parse_t *parse)
{
    for (int i = 0; parse->rooms[i].name != NULL; i++)
        if (my_strcomp(name, parse->rooms[i].name) == 1)
            return (1);
    return (0);
}

char **realloc_tunnel(char **arr, char *str)
{
    int size = double_tab_len(arr);
    char **new = malloc(sizeof(char *) * (size + 2));

    for (int i = 0; i < size + 1; i++) {
        if (arr[i] != NULL) {
            new[i] = malloc(sizeof(char) * (my_strlen(arr[i]) + 1));
            VERIF_MALLOC(new[i]);
            new[i] = my_getstr(arr[i]);
        }
    }
    new[size] = my_getstr(str);;
    new[size + 1] = NULL;
    free_array(arr);
    return (new);
}

static int error_tunnel2(char **array, int *status, parse_t *parse)
{
    if (check_same_tunnel(parse, array[0], status) == ERROR)
        return (ERROR);
    if ((parse->tunnel = realloc_tunnel(parse->tunnel, array[0])) == NULL) {
        *status = 83;
        return (ERROR);
    }
    return (SUCCESS);
}

static int error_tunnel(char **array, int *status, parse_t *parse)
{
    char *name = malloc(sizeof(char) * (my_strlen(array[0]) + 1));
    char *name2 = malloc(sizeof(char) * (my_strlen(array[0]) + 1));

    VERIF_INT_MALLOC(name);
    VERIF_INT_MALLOC(name2);
    if (tunnel_or_not(array[0]) == 0) {
        *status = 83;
        return (ERROR);
    }
    name = fill_string(array[0], name, 1);
    name2 = fill_string(array[0], name2, 2);
    if (name_gestion(name, name2, parse, status) == ERROR)
        return (ERROR);
    return (error_tunnel2(array, status, parse));
}

void check_tunnel(char *str, int *status, parse_t *parse)
{
    char **array = NULL;

    if (com_or_not(str) == 1)
        return;
    if ((array = get_arg_str(str, array)) == NULL) {
        *status = 83;
        return;
    }
    if (double_tab_len(array) != 1) {
        *status = 83;
        free_array(array);
        return;
    }
    if (error_tunnel(array, status, parse) == 84)
        return;
    my_putstr(parse->tunnel[double_tab_len(parse->tunnel) - 1]);
    my_putstr("\n");
    free_array(array);
}
