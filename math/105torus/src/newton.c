/*
** EPITECH PROJECT, 2019
** newton.c
** File description:
** newton
*/

#include "torus.h"

float next_newton(torus_t f, float x)
{
    if (solvef2x(f, x) == 0)
        exit (84);
    float soluce = x - (solvefx(f, x) / solvef2x(f, x));

    return(soluce);
}

void newton(torus_t f)
{
    float x = 0.5;
    float smaller = pow(10, -f.n);
    static int count = 0;

    printf("x = %.1f\n", x);
    while ((next_newton(f, x) - x) > smaller && count < 100){
        x = next_newton(f, x);
        printf("x = %.*f\n", f.n, x);
        count++;
    }
}