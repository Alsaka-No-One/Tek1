/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** useful_fonctions
*/

#include "lemin.h"
#include "struct.h"

char *check_com(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '#' || str[i] == '\n')
            str[i] = '\0';
    }
    return (str);
}

int com_or_not(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (i == 0 && str[i] == '#')
            return (1);
        else if (str[i] == '#')
            return (0);
        i++;
    }
    return (0);
}

char **get_arg_str(char *str, char **array)
{
    str = check_com(str);
    array = str_to_word_array(str);
    return (array);
}

int double_tab_len(char **array)
{
    int size = 0;

    while (array[size] != NULL)
        size++;
    return (size);
}
