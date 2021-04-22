/*
** EPITECH PROJECT, 2018
** CALC
** File description:
** this is a .c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/function.h"

int which_one_is_biggerte(char *str1, char *str2)
{
    int count1 = 0;
    int count2 = 0;

    if (str1[count1] == '-')
        count1++;
    if (str2[count2] == '-')
        count2++;
    while (str1[count1] != '\0'|| str2[count2] != '\0'){
        if (str1[count1] == str2[count2]){
            count1++;
            count2++;
        }
        if (str1[count1] > str2[count2])
            return (1);
        if (str2[count2] > str1[count1])
            return (2);
    }
    return (84);
}

char *number(char  *str, int *u, int p)
{
    int i = *u;
    char *nb;
    int signe = 1;
    int count = 0;

    nb = malloc (sizeof(char) * (my_strlen(str)));
    if (nb == NULL)
        return (0);
    while ((str[i] != '-' && str[i] < '0' || (str[i] > '9') 
            && (str[i] != '+')) && (str[i] != '\0'))
        i++;
    while (str[i] == '+' || str[i] == '-'){
        signe = str[i];
        i++;
    }
    if (signe == '-'){
        nb[count] = '-';
        count++;
    }
    else
        signe = 1;
    while (str[i] && str[i] >= '0' && str[i] <= '9'){
        nb[count] = str[i];
        i++;
        count++;
    }
    nb[count] = '\0';
    if (p == 1)
        *u = i;
    return (nb);
}

char *calcexpr(char *str)
{
    int u = 0;
    char *n;
    int c = 0;
    char *result;
    char *m;
    int t = 0;

    n = malloc (sizeof(char) * (my_strlen(str)));
    if (n == NULL)
	return (0);
    m = malloc (sizeof(char) * (my_strlen(str)));
    if (n == NULL)
        return (0);
    result = malloc (sizeof(char) * (my_strlen(str)));
    if (n == NULL)
        return (0);
    while (str[c] != '\0'){
        c++;
    }
    result = "00000000000000";
    m[0] = '0';
    while (u < c){
        n = "00000000000000";
        n = number(str, &u, 1);
        if (str[u] == '+' || str[u] == '-'){
            if (t == 0)
                result = addf(result, n);
            else {
                result = addf(result, m);
                t = 0;
            }
        }
        if (str[u] == '*'){
            if (t == 0){
                m = mult(n, number(str, &u, 0));
                t = 1;
            } else {
                m = mult(m, number(str, &u, 0));
                t = 1;
            }
        }
        if (str[u] == '/'){
            if (t == 0){
                m = itscience(n, number(str, &u, 0));
                t = 1;
            } else {
                m = itscience(m, number(str, &u, 0));
                t = 1;
            }
        }
        if (str[u] == '%'){
            if (t == 0){
                m = modul(n, number(str, &u, 0));
                t = 1;
            } else {
                m = modul(m, number(str, &u, 0));
                t = 1;
            }
	}
        if (str[u] == '\0'){
            if (t == 0)
                result = addf(result, n);
            else {
                result = addf(result, m);
            }
        }
    }
    u = 0;
    return (result);
}
