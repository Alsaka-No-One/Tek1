/*
** EPITECH PROJECT, 2018
** my_putint
** File description:
** my_putint
*/

#include<stdio.h>

int my_putint(int nb, int *countf, char *final)
{
    int count = 0;
    int test = 1;
    int a = 1;
    int lnb;
    int fir;
    int las;
    int c = *countf;
    
    if(nb < 0){
        final[c] ='-';
        c++;
        nb = nb * (-1);
    }
    while(nb > test){
        test = test * 10;
        count++;
    }
    while(count > 0){
        lnb = count;
        while(lnb > 1){
            a = a*10;
            lnb--;
        }
        fir = nb / a;
        las = fir % 10;
        final[c] = (las + 48);
        c++;
        count--;
        a = 1;
    }
    *countf = c;
}
