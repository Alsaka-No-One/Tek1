/*
** EPITECH PROJECT, 2018
** my_compute_power_rec
** File description:
** Task04
*/

int my_compute_power_rec (int nb , int p)
{
    int nb2 = nb;

    if (p == 0){
        return (1);
    }
    if (p < 0){
        return(0);
    }
    else{
        nb = nb2 * my_compute_power_rec(nb, p - 1);  
    }
    return(nb);
}
