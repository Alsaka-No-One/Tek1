/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** useful_fonction_two
*/

#include "lemin.h"
#include "struct.h"

int my_str_isalphanum(char *str)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != '\n') {
        if (!(str[i] >= 'a' && str[i] <= 'z')
        && !(str[i] >= '0' && str[i] <= '9'))
        return (0);
        i++;
    }
    return (1);
}

char *my_getstr(char *str)
{
    int size = my_strlen(str);
    char *cpy = malloc(sizeof(char) * (size + 1));

    if (cpy == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++)
        cpy[i] = str[i];
    cpy[size] = '\0';
    return (cpy);
}