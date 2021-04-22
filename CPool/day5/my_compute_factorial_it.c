/*
** EPITECH PROJECT, 2018
** my_compute_factorial_it
** File description:
** Task01
*/

int my_compute_factorial_it(int nb)
{
    int nbr = nb - 1;

    if (nb < 0 || nb >= 13){
        return (0);
    }
    if (nb == 0){
        return (1);
    }
    if (nb == 1){
        return (1);
    }
    while (nbr >= 1){
        nb = nb * nbr;
        nbr --;
    }
    return (nb);
}
