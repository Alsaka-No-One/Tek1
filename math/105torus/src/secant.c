/*
** EPITECH PROJECT, 2019
** Maths torus | secant
** File description:
** The secant method
*/

#include "torus.h"

float next_secant(torus_t f, float x0, float x1, int i)
{
    if ((solvefx(f, x1) - solvefx(f, x0)) == 0)
        exit (84);
        
    float x2 = x1 - ((solvefx(f, x1) * (x1 - x0)) / (solvefx(f, x1) - solvefx(f, x0)));

    if (i == 0)
        printf("x = %.1f\n", x2);
    else
        printf("x = %.*f\n", f.n, x2);
    return(x2);
}

float absolute(float nb)
{
    if (nb < 0)
        return (nb * -1);
    else
        return (nb);
}

void secant(torus_t f)
{
    float x0 = 0;
    float x1 = 1;
    float x2;
    float smaller = pow(10, -f.n);
    static int count = 0;

    while (absolute((x2 = next_secant(f, x0, x1, count)) - x1) > smaller && count < 200){
        x0 = x1;
        x1 = x2;
        count++;
    }
}
