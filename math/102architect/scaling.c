/*
** EPITECH PROJECT, 2018
** scaling.c
** File description:
** scaling
*/

#include "architect.h"

void scaling(float **matrice_r, char *vector_x, char *vector_y)
{
    float **matrice = initialize_matrice();

    printf("Scaling by factors %s and %s\n", vector_x, vector_y);
    matrice[0][0] = atof(vector_x);
    matrice[1][1] = atof(vector_y);
    mult_matrice(matrice_r, matrice);
}
