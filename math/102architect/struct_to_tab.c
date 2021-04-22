/*
** EPITECH PROJECT, 2018
** Maths 102architect | vector_to_tab
** File description:
** Function that create a tab from a vector
*/

#include "architect.h"

float *vector_to_tab(vector_t vector)
{
    float *tab = malloc(sizeof(float) * 3);

    tab[0] = vector.x;
    tab[1] = vector.y;
    tab[2] = vector.z;
    return (tab);
}

void remplace_matrice(float **matrice_r, float **matrice_rr)
{
    matrice_r[0][0] = matrice_rr[0][0];
    matrice_r[0][1] = matrice_rr[0][1];
    matrice_r[0][2] = matrice_rr[0][2];
    matrice_r[1][0] = matrice_rr[1][0];
    matrice_r[1][1] = matrice_rr[1][1];
    matrice_r[1][2] = matrice_rr[1][2];
}

void mult_matrice(float **matrice_r, float **matrice)
{
    float **matrice_rr = initialize_matrice();

    matrice_rr[0][0] = 0;
    matrice_rr[1][1] = 0;
    matrice_rr[2][2] = 0;
    for (int i = 0; i < 3; i++)
        matrice_rr[0][0] += matrice_r[0][i] * matrice[i][0];
    for (int i = 0; i < 3; i++)
        matrice_rr[0][1] += matrice_r[0][i] * matrice[i][1];
    for (int i = 0; i < 3; i++)
        matrice_rr[0][2] += matrice_r[0][i] * matrice[i][2];
    for (int i = 0; i < 3; i++)
        matrice_rr[1][0] += matrice_r[1][i] * matrice[i][0];
    for (int i = 0; i < 3; i++)
        matrice_rr[1][1] += matrice_r[1][i] * matrice[i][1];
    for (int i = 0; i < 3; i++)
        matrice_rr[1][2] += matrice_r[1][i] * matrice[i][2];
    remplace_matrice(matrice_r, matrice_rr);
}

vector_t calcul_vector_result(vector_t vector, float **matrice)
{
    vector_t vector_r = {0, 0, 0};
    float *tab = vector_to_tab(vector);

    for (int i = 0; i < 3; i++)
        vector_r.x += tab[i] * matrice[0][i];
    for (int i = 0; i < 3; i++)
        vector_r.y += tab[i] * matrice[1][i];
    return (vector_r);
}
