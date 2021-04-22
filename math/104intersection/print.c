/*
** EPITECH PROJECT, 2018
** 104intersection_2018
** File description:
** print
*/

#include <unistd.h>
#include "intersection.h"

void print_usage(void)
{
    printf("USAGE\n");
    printf("    ./104intersection opt xp yp zp xv yv zv p\n\n");
    printf("DESCRIPTION\n");
    printf("    opt                 surface option: 1 for a sphere, 2 for a cylinder, 3 for a cone\n");
    printf("    (xp, yp, zp)        coordinates of a point by which the light ray passes through\n");
    printf("    (xv, yv, zv)        coordinates of a vector parallel to the light ray\n");
    printf("    p                   parameter: radius of the sphere, radius of the cylinder, or\n");
    printf("                        angle formed by the cone and the Z-axis\n");
}