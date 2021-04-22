/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** parse_nb_ants
*/

#include "lemin.h"
#include "struct.h"

void check_nb_ants(char **array, int *status, parse_t *parse)
{
    if (my_getnbr(array[0]) >= 0) {
        *status = 2;
        parse->nb_ants = my_getnbr(array[0]);
        my_put_nbr(parse->nb_ants);
        my_putstr("\n#rooms\n");
        return;
    } else
        *status = 84;
    return;
}

void find_nb_ants(char *str, int *status, parse_t *parse)
{
    char **array = NULL;

    if (com_or_not(str) == 1)
        return;
    if ((array = get_arg_str(str, array)) == NULL) {
        *status = 84;
        return;
    } if (double_tab_len(array) != 1) {
        *status = 84;
        free_array(array);
        return;
    }
    check_nb_ants(array, status, parse);  
    free_array(array);
}