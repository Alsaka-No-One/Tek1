/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "architect.h"

void find_calcul(char **av, float **matrice, int i)
{
    char *comp[5] = {"-t", "-z", "-r", "-s", ""};
    void (*ptd[4]) (float **, char *, char *) =
        {translation, scaling, rotation, reflection};
    int k = 0;

    while (comp[k][0] != '\0' && my_str_eg(av[i], comp[k]) != 1)
    k++;
    if (my_str_eg(av[i], comp[k]) == 1)
        (*ptd[k]) (matrice, av[i + 1], av[i + 2]);
}

float **initialize_matrice(void)
{
    float **matrice = malloc(sizeof(float *) * 3);

    if (matrice == NULL)
        exit(84);
    for (int i = 0; i < 3; i++) {
        matrice[i] = malloc(sizeof(float) * 3);
        for (int j = 0; j < 3; j++)
            matrice[i][j] = 0;
    }
    matrice[0][0] = 1;
    matrice[1][1] = 1;
    matrice[2][2] = 1;
    return (matrice);
}

void manage_calcul(char **av, int ac)
{
    vector_t vector_ini = get_vector(av[1], av[2]);
    vector_t vector_result = get_vector(av[1], av[2]);
    float **matrice_result = initialize_matrice();

    for (int i = ac - 1; i != 2; i--)
        find_calcul(av, matrice_result, i);
    vector_result = calcul_vector_result(vector_ini, matrice_result);
    display_result(matrice_result, vector_result, vector_ini);
    free(matrice_result);
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    if (my_str_eg(av[1], "-h") == 1)
        disp_usage();
    manage_calcul(av, ac);
    return (0);
}
