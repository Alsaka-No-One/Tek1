/*
** EPITECH PROJECT, 2019
** duo stumper 2
** File description:
** find a string in another string
*/

#include <unistd.h>
#include <stdio.h>

int nb_char_str(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;

    return (i);
}

int find_str(char *str, char *str2)
{
    int x = 0;
    int y = 0;
    int j = 0;
    int a = nb_char_str(str);

    while (str2[y] != '\0') {
        if (str[x] == str2[y]) {
            j++;
            x++;
            y++;
        } else
            y++;
    }
    if (j == a) {
        return (1);
    }
    else {
        return (-1);
    }
    return (0);
}

