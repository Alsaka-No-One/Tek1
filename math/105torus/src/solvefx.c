/*
** EPITECH PROJECT, 2019
** solvefx
** File description:
** solvefx
*/

#include "torus.h"

float solvefx(torus_t f, float x)
{
    float soluce = (f.a0 * pow(x, 4)) + (f.a1 * pow(x, 3)) + (f.a2 * pow(x, 2)) + (f.a3 * x) + f.a4;

    return (soluce);
}

float solvef2x(torus_t f, float x)
{
    float soluce = (4 * f.a0 * pow(x, 3)) + (3 * f.a1 * pow(x, 2)) + (2 * f.a2 * x) + f.a3;

    return(soluce);
}