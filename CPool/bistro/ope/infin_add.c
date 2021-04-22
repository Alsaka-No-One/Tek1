/*
** EPITECH PROJECT, 2018
** Infin_add
** File description:
** Task00
*/

#include <stdlib.h>
#include <unistd.h>

int which_one_is_bigger(char *str1, char *str2)
{
    int count1 = 0;
    int count2 = 0;

    if (str1[count1] == '-')
        count1++;
    if (str2[count2] == '-')
        count2++;
    while (str1[count1] != '\0'|| str2[count2] != '\0') {
        if (str1[count1] == str2[count2]) {
            count1++;
            count2++;
        }
        if (str1[count1] > str2[count2])
            return (1);
        if (str2[count2] > str1[count1])
            return (2);
    }
}

int my_putstrc(char const *str, int sous)
{
    int compt;
    int ut = 0;

    if (sous == 1)
        my_putchar ('-');
    compt = 0;
    while (str[compt] == '0')
        compt++;
    while (str[compt] != '\0') {
        if (str[compt] >=0 && str[compt])
            my_putchar (str[compt]);
        compt =  compt + 1;
        ut++;
    }
    if (ut == 0)
        my_putchar('0');
    my_putchar('\n');
}

int counter(char *nb)
{
    int i = 0;

    while (nb[i] != '\0')
        i ++;
    return (i);
}

int add (int n1, int n2, int *ret, int signe1, int signe2, int *sret, int sous)
{
    int d3;
    int d1 = n1 - 48;
    int d2 = n2 - 48;
    int lret = *ret;
    int sousret = *sret;

    if (d1 < 0 || d2 > 9)
        d1 = 0;
    if (d2 < 0 || d2 > 9)
        d2 = 0;
    if (signe1 == 1)
        d1 = d1 * (-1);
    if (signe2 == 1)
        d2 = d2 * (-1);
    if (sous == 1) {
        d1 = d1 * (-1);
        d2 = d2 * (-1);
    }
    if (((d1 + d2 + lret - sousret) < 10) &&
        ((d1 + d2 + lret - sousret) >= 0)) {
        d3 = d1 + d2 + lret - sousret;
        *ret = 0;
        *sret = 0;
    }
    else if ((d1 + d2 + lret - sousret) < 0) {
        d3 = 10 + (d1 + d2 - sousret);
        *sret = 1;
    }
    else if ((d1 + d2 + lret - sousret) >= 10) {
        d3 = (d1 + d2 + lret) - 10;
        *ret = 1;
    }
    return (d3);
}

int main (int ac, char **av)
{
    int nd1;
    int nd2;
    int ndm;
    char *dest;
    int ret = 0;
    int sret = 0;
    int signe1 = 0;
    int signe2 = 0;
    int sous = 0;

    nd1 = counter(av[1]) - 1;
    nd2 = counter(av[2]) - 1;
    if (nd1 <= nd2)
        ndm = nd2 + 1;
    else
        ndm = nd1 + 1;
    dest = malloc (sizeof(char) * (ndm + 2));
    if (dest == NULL)
        return (0);
    if (av[1][0] == '-') {
        if (nd1 > nd2 + 1)
            sous = 1;
        if ((nd1 == nd2 + 1) && (which_one_is_bigger(av[1], av[2]) == 1))
            sous = 1;
        signe1 = 1;
    }
    if (av[2][0] == '-') {
        if (nd2 > nd1 + 1)
            sous = 1;
        if ((nd1 == nd2 - 1) && (which_one_is_bigger(av[1], av[2]) == 2))
            sous = 1;
        signe2 = 1;
    }
    while (ndm >= 0) {
        dest[ndm] = add(av[1][nd1], av[2][nd2],
                        &ret, signe1, signe2, &sret, sous);
        dest[ndm] = dest[ndm] + 48;
        ndm--;
        if (nd1 >= 0)
            nd1--;
        if (nd2 >= 0)
            nd2--;
    }
    my_putstrc (dest, sous); 
    return (0);
}
