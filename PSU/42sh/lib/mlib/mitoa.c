/*
** EPITECH PROJECT, 2018
** mlib
** File description:
** int to char
*/

#include <stdlib.h>

int mpow(int nbr, int pow)
{
    int result = 0;

    if (pow == 0)
        return (1);
    if (nbr == 0)
        return (0);
    result += nbr;
    for (int i = 1 ; i < pow ; i++)
        result *= nbr;
    return (result);
}

char *mitoa(int nbr)
{
    char *str = NULL;
    int nbr_cp = nbr;
    int i = 0;
    int max = 0;

    if (nbr == 0)
        return ("0\0");
    for (i = 0 ; nbr_cp >= 1 ; i++, nbr_cp /= 10);
    str = malloc(sizeof(char *) * (i + 1));
    max = i;
    str[i--] = '\0';
    for (int count = 0 ; count < max ; i--, count++) {
        str[count] = nbr / (int)mpow(10, i) + '0';
        nbr %= (int) mpow(10, i);
    }
    return (str);
}
