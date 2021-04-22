/*
** EPITECH PROJECT, 2018
** main
** File description:
** main?
*/

#include <stdio.h>
#include <stdlib.h>

char *itscience(char *n1, char *n2);
char *mult(char *n1, char *n2);
int my_strlen(char const *str);
char *addf(char *n1, char *n2);

char *modul(char *n1, char *n2)
{
    char *result;
    char *mone;

    result = malloc(sizeof (char) * (my_strlen(n1)+1));
    mone = malloc(sizeof (char) * 2);
    mone[0] = '-';
    mone[1] = '1';
    result = itscience(n1, n2);
    result = mult(result, n2);
    result = mult(mone, result);
    result = addf(n1, result);
    return(result);
}
