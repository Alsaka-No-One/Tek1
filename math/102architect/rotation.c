/*
** EPITECH PROJECT, 2018
** rotation.c
** File description:
** rotation
*/

#include "architect.h"

void rotation(float **matrice_r, char *angle_rotation, char *nothing)
{
    float angle_r = atof(angle_rotation);
    float **matrice = initialize_matrice();

    printf("Rotation by a %.0f degree angle\n", angle_r);
    matrice[0][0] = cos((angle_r / 180) * M_PI);
    matrice[0][1] = -sin((angle_r / 180) * M_PI);
    matrice[1][0] = sin((angle_r / 180) * M_PI);
    matrice[1][1] = cos((angle_r / 180) * M_PI);
    mult_matrice(matrice_r, matrice);
}
