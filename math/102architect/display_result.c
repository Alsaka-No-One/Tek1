/*
** EPITECH PROJECT, 2018
** display_result.c
** File description:
** display result
*/

#include "architect.h"

void display_result(float **matrice, vector_t vector, vector_t vector_ini)
{
    printf("%.2f    %.2f    %.2f\n", matrice[0][0],
        matrice[0][1], matrice[0][2]);
    printf("%.2f    %.2f    %.2f\n", matrice[1][0],
        matrice[1][1], matrice[1][2]);
    printf("%.2f    %.2f    %.2f\n", matrice[2][0],
        matrice[2][1], matrice[2][2]);
    printf("(%.0f, %.0f) => (%.2f, %.2f)\n", vector_ini.x,
        vector_ini.y, vector.x, vector.y);
}
