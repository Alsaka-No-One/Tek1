/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** Task05
*/

#include "include/function.h"

int compt_in_str(char const *str)
{
    int i = 0;

    while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
        i++;
    return (i);
}

int my_getnbr(char const *str)
{
    int compt = compt_in_str(str);
    int P = 1;
    int down = compt;
    int nb = 0;

    while ((str[down] <= '9') && (str[down] >= '0'))
        down ++;
    down --;
    while (down >= compt){
        nb = nb + (str[down] - 48) * P;
        P = P * 10;
        down --;
    }
    return (nb);
}
