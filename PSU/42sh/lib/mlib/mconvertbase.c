/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** Converts decimal integer to another base
*/

#include <stdlib.h>

static char *revstr(char *str)
{
    int size = 0;
    char *temp = NULL;
    int row = 0;

    for ( ; str[size] ; size++);
    temp = malloc(sizeof(char *) * (size + 1));
    if (!temp)
        return (NULL);
    for (int i = size - 1 ; i >= 0 ; --i)
        temp[row++] = str[i];
    temp[row] = '\0';
    return (temp);
}

char mconvertbase1(int nbr)
{
    if (0 <= nbr && nbr <= 9)
        return (nbr + '0');
    return (nbr - 10 + 'a');
}

char *mconvertbase(int nbr, int base)
{
    char *result;
    char *rev_result;
    long int nbr_cpy = nbr;
    int i = 0;

    if (nbr <= 0)
        return ("0");
    for (i = 0 ; nbr_cpy > 1 ; nbr_cpy /= base, i++);
    if (!(result = malloc(sizeof(char *) * (i + 1))))
        return (NULL);
    i = 0;
    while (nbr != 0) {
        result[i++] = mconvertbase1(nbr % base);
        nbr /= base;
    }
    result[i] = '\0';
    if (!(rev_result = revstr(result)))
        return (NULL);
    free(result);
    return (rev_result);
}
