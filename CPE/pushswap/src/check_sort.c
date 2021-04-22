/*
** EPITECH PROJECT, 2018
** CPE pushswap | check_sort
** File description:
** The function to check if the list is already sort or not
*/

#include "../include/pushswap.h"

int check_sort(list_t **list)
{
    list_t *temp = *list;

    while (temp->next != NULL) {
        if (temp->nb > temp->next->nb)
            return (1);
        temp = temp->next;
    }
    return (0);
}