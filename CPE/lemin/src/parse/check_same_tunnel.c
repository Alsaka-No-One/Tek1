/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** check_same_tunnel
*/

#include "lemin.h"
#include "struct.h"

static void free_all(char *before, char *after, char *aft, char *bef)
{
    free(before);
    free(after);
    free(aft);
    free(bef);
}

static int check_reverse(char *tunnel, char *str)
{
    char *before = malloc(sizeof(char) * (my_strlen(str) + 1));
    char *after = malloc(sizeof(char) * (my_strlen(str) + 1));
    char *aft_tun = malloc(sizeof(char) * (my_strlen(tunnel) + 1));
    char *bef_tun = malloc(sizeof(char) * (my_strlen(tunnel) + 1));

    VERIF_INT_MALLOC(before);
    VERIF_INT_MALLOC(after);
    VERIF_INT_MALLOC(aft_tun);
    VERIF_INT_MALLOC(bef_tun);
    before = fill_string(str, before, 1);
    bef_tun = fill_string(tunnel, bef_tun, 1);
    after = fill_string(str, after, 2);
    aft_tun = fill_string(tunnel, aft_tun, 2);
    if (my_strcomp(before, aft_tun) == 1
        && my_strcomp(after, bef_tun) == 1)
        return (-1);
    free_all(before, after, aft_tun, bef_tun);
    return (1);
}

int check_same_tunnel(parse_t *parse, char *str, int *status)
{
    int nb_tun = 0;

    for (int i = 0; parse->tunnel[i] != NULL; i++) {
        if (my_strcomp(parse->tunnel[i], str) == 1) {
            my_putstr(str);
            my_putstr("\n");
            return (ERROR);
        }
        if (check_reverse(parse->tunnel[i], str) == -1) {
            my_putstr(str);
            my_putstr("\n");
            return (ERROR);
        }
    }
    return (SUCCESS);
}