/*
** EPITECH PROJECT, 2018
** CPE pushswap | allowed function
** File description:
** The functions allowed to make the pushswap
*/

#include "../include/pushswap.h"

void sa_sb(list_t **list)
{
    list_t *temp = NULL;

    if (*list != NULL || (*list)->next != NULL) {
        temp = (*list)->next;
        (*list)->next = temp->next;
        temp->next = *list;
        *list = temp;
    }
}

void sc(list_t **list1, list_t **list2)
{
    sa_sb(list1);
    sa_sb(list2);
}

void pa_pb(list_t **list1, list_t **list2)
{
    list_t *temp = NULL;

    if (*list2 != NULL) {
        temp = (*list2)->next;
        (*list2)->next = *list1;
        *list1 = *list2;
        *list2 = temp;
    }
}

void ra_rb(list_t **list)
{
    list_t *temp = *list;
    list_t *copy = *list;

    if (*list != NULL) {
        copy = *list;
        while (copy->next != NULL)
            copy = copy->next;
        copy->next = *list;
        temp = (*list)->next;
        (*list)->next = NULL;
        *list = temp;
    }
}

void rr(list_t **list1, list_t **list2)
{
    ra_rb(list1);
    ra_rb(list2);
}