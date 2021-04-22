/*
** EPITECH PROJECT, 2018
** tree.c
** File description:
** 
*/

void leaf (int stars)
{
    int compts;

    for (compts = 1; compts <= stars; compts ++){
        my_putchar ('*');
    }
    my_putchar ('\n');
}

int stagenbr ( int stage, int stars)
{
    int i = 1;
    int lines = stage + 3;

    while (i <= lines){
        leaf (stars);
        stars = stars + 2;
        i++;
   }
   return (stars);
}

void tree(int size)
{
    int lag = 2;
    int stars = 1;
    int l1 = 1;
    int l2 = 2;
    int i = 1;

    while (i <= size){
        stars = stagenbr (i, stars);
        l1 = l1 + 1;
        if (l1 == l2){
            lag = lag + 1;
            l2 = l2 + 2;
        }
        stars = stars - lag;
        i++;
    }
}
