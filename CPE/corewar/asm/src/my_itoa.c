/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_itoa
*/

#include <stdlib.h>

int my_nbrlen(int nbr)
{
    int count = 0;

    while (nbr > 0){
        nbr = nbr / 10;
        count++;
    }
    return (count);
}

int mult_by_ten(int nbr)
{
    int a = 1;

    while (nbr > 0){
        nbr--;
        a = a * 10;
    }
    return (a);
}

int take_digit(int nbr, int count)
{
    int digit;
    int len = my_nbrlen(nbr);
    int a;

    a = mult_by_ten (len - count);
    digit = nbr / a % 10;
    return (digit);
}

int antinega(int nega)
{
    if (nega == 1)
        return (0);
    return (1);
}

char *my_itoa(int nbr)
{
    char *str = malloc (sizeof(char) * (my_nbrlen(nbr) + 20));
    int count = my_nbrlen(nbr);
    int nega = 1;

    if (nbr == 0) {
        str[0] = '0';
        str[1] = '\0';
        return (str);
    }
    if (nbr < 0) {
        str[0] = '-';
        nbr = nbr * -1;
        count = my_nbrlen(nbr);
        nega = 0;
    }
    while (count > 0){
        str[count - nega] = take_digit(nbr, count) + 48;
        count--;
    }
    str[my_nbrlen(nbr) + antinega(nega)] = '\0';
    return (str);
}