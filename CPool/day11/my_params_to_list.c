/*
** EPITECH PROJECT, 2018
** my_params_to_list
** File description:
** Task01
*/

#include <stdlib.h>
#include "include/mylist.h"

linked_list_t *transf(linked_list_t *list, char *word)
{
    linked_list_t *tmp;

    tmp = malloc(sizeof(linked_list_t));
    if (tmp == NULL)
        return (tmp);
    tmp -> data = word;
    tmp -> next = list;
    return (tmp);
}

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    linked_list_t *list;
    int i = 0;

    list = NULL;
    while (i < ac){
        list = transf (list, av[i]);
        i++;
    }
    return (list);
}
