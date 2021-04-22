/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** my_put_nbr
*/

#include <unistd.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}

int my_put_nbr(int nb)
{
    int count = 0;
    int test = 1;
    int a = 1;
    int lnb;
    int fir;
    int las;
    
    if(nb < 0){
        my_putchar('-');
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
        my_putchar(las + 48);
        count--;
        a = 1;
    }
    my_putchar('\n');
}
