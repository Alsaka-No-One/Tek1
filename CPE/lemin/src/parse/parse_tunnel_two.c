/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** parse_tunnel_two
*/

#include "lemin.h"
#include "struct.h"

int name_gestion(char *name, char *name2, parse_t *parse, int *status)
{
    if (my_strcomp(name, name2) == 1) {
        *status = 83;
        free(name);
        free(name2);
        return (ERROR);
    }
    if (check_name(name, parse) != 1
        || check_name(name2, parse) != 1) {
        *status = 83;
        free(name);
        free(name2);
        return (ERROR);
    }
}

int tunnel_or_not(char const *str)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            j++;
    }
    if (j != 1)
        return (0);
    return (1);
}

char *get_second_name(char *src, char *dest, int *i, int *j)
{
    while ((src[*j] >= 'a' && src[*j] <= 'z')
        || (src[*j] >= '0' && src[*j] <= '9')) {
        dest[*i] = src[*j];
        (*i)++;
        (*j)++;
    }
    dest[*i] = '\0';
    return (dest);
}

char *fill_string(char *src, char *dest, int status)
{
    int j = 0;
    int i = 0;

    if (status == 1) {
        for (i = 0; src[i] != '-'; i++) {
            dest[i] = src[i];
            j = i;
        }
        dest[j + 1] = '\0';
        return (dest);
    }
    if (status == 2) {
        while (src[j] != '-')
            j++;
        j++;
        return (get_second_name(src, dest, &i, &j));
    }
}
