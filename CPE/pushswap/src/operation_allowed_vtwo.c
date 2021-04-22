/*
** EPITECH PROJECT, 2018
** CPE pushswap | allowed function v2
** File description:
** The second part of allowed functions
*/

#include "../include/pushswap.h"

void rra_rrb(list_t **list)
{
    list_t *temp = NULL;
    list_t *temp2 = NULL;

    if (*list != NULL) {
        temp = *list;
        temp2 = *list;
        while (temp->next != NULL)
            temp = temp->next;
        while (temp2->next->next != NULL)
            temp2 = temp2->next;
        temp->next = *list;
        temp2->next = NULL;
        *list = temp;
    }
}

void rrr(list_t **list1, list_t **list2)
{
    rra_rrb(list1);
    rra_rrb(list2);
}