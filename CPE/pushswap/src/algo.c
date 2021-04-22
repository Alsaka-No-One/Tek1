/*
** EPITECH PROJECT, 2018
** CPE pushswap | algo
** File description:
** the algorythm to sort the list
*/

#include "../include/pushswap.h"

int check_biggest_number(list_t **list)
{
    list_t *temp = NULL;
    int max;
    int next;

    temp = *list;
    max = temp->nb;
    if (max < 0)
        max *= -1;
    while (temp->next != NULL) {
        next = temp->next->nb;
        if (next < 0)
            next *= -1;
        if (max <= next)
            max = next;
        temp = temp->next;
    }
    return (max);
}

int position(list_t **list)
{
    list_t *temp = *list;
    int max = check_biggest_number(list);
    int i = 0;
    int nb = temp->nb;

    (nb < 0) ? nb *= -1 : 0;
    while (nb != max && temp->next != NULL) {
        nb = temp->nb;
        if (nb < 0)
            nb *= -1;
        if (nb == max)
            break;
        temp = temp->next;
    }
    while (temp->nbr[i] != '1')
        i++;
    return (i);
}

void separate_list(list_t **list1, list_t **list2, int argc)
{
    list_t *temp = NULL;
    int i = 1;

    while (i != argc) {
        temp = *list1;
        if (temp->nb < 0) {
            pa_pb(list2, list1);
            write (1, "pb ", 3);
            ra_rb(list2);
            write(1, "ra ", 3);
        }
        if (temp->nb >= 0) {
            ra_rb(list1);
            write(1, "ra ", 3);
        }
        temp = temp->next;
        i++;
    }
    easy_sort(list1, list2, 1);
}

void easy_sort(list_t **list1, list_t **list2, int status)
{
    if (status == 0) {
        if ((*list1)->nb >= (*list1)->next->nb) {
            sa_sb(list1);
            write(1, "sa", 2);
        }
        write(1, "\n", 1);
    }
    else if (status == 1) {
        while (*list2 != NULL) {
            pa_pb(list1, list2);
            write(1, "pa ", 3);
        }
    }
}

void algo(list_t **list1, list_t **list2, int stop_condition, int argc)
{
    int i = NB_SIZE - 1;
    int ii = 0;

    while (i >= stop_condition) {
        if ((*list1)->nbr[i] == '1'){
            ra_rb(list1);
            write(1, "ra ", 3);
        } else {
            pa_pb(list2, list1);
            write(1, "pb ", 3);
        }
        ii++;
        if (ii == argc - 1) {
            easy_sort(list1, list2, 1);
            ii = 0;
            i--;
        }
    }
}