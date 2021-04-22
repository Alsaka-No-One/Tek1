/*
** EPITECH PROJECT, 2019
** Maths torus | deriv
** File description:
** The function that return the result of the deriv
*/

#include "torus.h"

interv_t bisection_method(torus_t function, interv_t bet, int i)
{
    float midpoint = 0.0;

    midpoint = (bet.xmin + bet.xmax) / 2;
    if ((solvefx(function, bet.xmin) * solvefx(function, midpoint)) < 0) {
        if (bet.xmax == midpoint)
            exit(0);
        bet.xmax = midpoint;
        if (i < function.n)
            printf("x = %.*f\n", i + 1, bet.xmax);
        else
            printf("x = %.*f\n",function.n, bet.xmax);
        return (bet);
    } else if ((solvefx(function, bet.xmin) * solvefx(function, midpoint)) > 0) {
        if (bet.xmin == midpoint)
            exit(0);
        bet.xmin = midpoint;
        if (i < function.n)
            printf("x = %.*f\n", i + 1, bet.xmin);
        else
            printf("x = %.*f\n", function.n, bet.xmin);
        return (bet);
    }
}

float mid_find(interv_t bet)
{
    float midpoint = (bet.xmin + bet.xmax) / 2;
    return (midpoint);
}

void bisection_function(torus_t function)
{
    interv_t result;
    float limit = pow(10, -function.n);
    int i = 0;

    result.xmin = 0.0;
    result.xmax = 1.0;
    while (mid_find(result) > limit && i != 200) {
        result = bisection_method(function, result, i);
        i++;
    }
}