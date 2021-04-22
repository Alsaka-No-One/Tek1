/*
** EPITECH PROJECT, 2018
** translation.c
** File description:
** translation
*/

#include "architect.h"

void translation(float **matrice_r, char *vector_x, char *vector_y)
{
    float **matrice = initialize_matrice();

    printf("Translation along vector (%s, %s)\n", vector_x, vector_y);
    matrice[0][2] = atof(vector_x);
    matrice[1][2] = atof(vector_y);
    mult_matrice(matrice_r, matrice);
}
