/*
** EPITECH PROJECT, 2018
** my_compute_factorial_rec
** File description:
** Task02
*/

int my_compute_factorial_rec(int nb)
{
    if (nb <= 0){
        return (0);
    }
    if (nb == 1){
        return(1);
    }
    else {
        nb = nb * my_compute_factorial_rec(nb - 1);
    }

    return (nb);
}
