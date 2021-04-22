/*
** EPITECH PROJECT, 2018
** 104intersection_2018
** File description:
** formule
*/

#include "intersection.h"

coord_t form_sphere(char **argv)
{
    coord_t coord;
    coord.x = pow(atof(argv[5]), 2) + pow(atof(argv[6]), 2) + pow(atof(argv[7]), 2);
    coord.y = 2 * ((atof(argv[2]) * atof(argv[5])) + (atof(argv[3]) * atof(argv[6])) + (atof(argv[4]) * atof(argv[7])));
    coord.z = pow(atof(argv[2]), 2) + pow(atof(argv[3]), 2) + pow(atof(argv[4]), 2) - pow(atof(argv[8]), 2);
    return (coord);
}

coord_t form_cylinder(char **argv)
{
    coord_t coord;
    coord.x = pow(atof(argv[5]), 2) + pow(atof(argv[6]), 2);
    coord.y = 2 * ((atof(argv[2]) * atof(argv[5])) + (atof(argv[3]) * atof(argv[6])));
    coord.z = pow(atof(argv[2]), 2) + pow(atof(argv[3]), 2) - pow(atof(argv[8]), 2);
    return (coord);
}

coord_t form_cone(char **argv, int angle)
{
    coord_t coeff;
    float angle_r = (angle * M_PI) / 180;
    coeff.x = pow(atof(argv[5]), 2) + pow(atof(argv[6]), 2) - (pow(atof(argv[7]), 2) * pow(tan(angle_r), 2));
    coeff.y = (2 * atof(argv[2]) * atof(argv[5])) + (2 * atof(argv[3]) * atof(argv[6])) - (2 * atof(argv[4]) * atof(argv[7]) * pow(tan(angle_r), 2));
    coeff.z = pow(atof(argv[2]), 2) + pow(atof(argv[3]), 2) - pow(atof(argv[4]), 2) * pow(tan(angle_r), 2);
    return (coeff);
}
