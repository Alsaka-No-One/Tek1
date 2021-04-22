/*
** EPITECH PROJECT, 2018
** Maths 102architect | get_coord_vector
** File description:
** The function that return the coords of the vector
*/

#include <stdlib.h>
#include "architect.h"

vector_t get_vector(char *char_x, char *char_y)
{
    vector_t vector;

    vector.x = atof(char_x);
    vector.y = atof(char_y);
    vector.z = 1;
    return (vector);
}
