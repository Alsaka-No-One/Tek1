/*
** EPITECH PROJECT, 2018
** my_compute_power_it
** File description:
** Task03
*/

int my_compute_power_it (int nb , int p)
{
    int i = 1;
    int nb2 = nb;

    if (p == 0){
        return(1);
    }
    if (p < 0){
        return(0);
    }
    else{
        while (i != p){
            nb = nb * nb2;
            i++;
        }
    }
    return(nb);
}
