/*
** EPITECH PROJECT, 2018
** CPE pushswap
** File description:
** header
*/

#ifndef __PUSHSWAP_H
#define __PUSHSWAP_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#define NB_SIZE 33

typedef struct list_s {
    char nbr[NB_SIZE];
    int nb;
    struct list_s *next;
} list_t;

int my_getnbr(char const *);
void sa_sb(list_t **);
void sc(list_t **, list_t **);
void pa_pb(list_t **, list_t **);
void ra_rb(list_t **);
void rr(list_t **, list_t **);
void rra_rrb(list_t **);
void rrr(list_t **, list_t **);
void algo(list_t **, list_t **, int, int);
void separate_list(list_t **, list_t **, int);
void easy_sort(list_t **, list_t **, int);
int check_biggest_number(list_t **);
int position(list_t **);
int check_sort(list_t **list);
int error_argument(int, char **);

#endif
