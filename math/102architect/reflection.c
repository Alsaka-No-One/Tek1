/*
** EPITECH PROJECT, 2018
** reflection.c
** File description:
** reflection
*/

#include "architect.h"

void reflection(float **matrice_r, char *angle_reflection, char *nothing)
{
    float angle_r = atof(angle_reflection);
    float **matrice = initialize_matrice();

    printf("Reflection over an axis with an inclination angle of %.0f degrees\n", angle_r);
    matrice[0][0] = cos((2 * (angle_r / 180) * M_PI));
    matrice[0][1] = sin((2 *(angle_r / 180) * M_PI));
    matrice[1][0] = sin((2 * (angle_r / 180) * M_PI));
    matrice[1][1] = -cos((2 * (angle_r / 180) * M_PI));
    mult_matrice(matrice_r, matrice);
}
