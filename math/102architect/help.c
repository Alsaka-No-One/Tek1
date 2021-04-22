/*
** EPITECH PROJECT, 2018
** Maths 102architect | help.c
** File description:
** The usage of the function
*/

#include "architect.h"

void disp_usage(void)
{
    printf("USAGE\n");
    printf("\t./102architect x y transfo1 arg11 [arg12] [transfo2 ");
    printf("arg12 [arg22]] ...\n");
    printf("\n");
    printf("DESCRIPTION\n");
    printf("\tx\tabscissa of the original point\n");
    printf("\ty\tordinate of the original point\n");
    printf("\n");
    printf("\ttransfo arg1 [arg2]\n");
    printf("\t-t i j\t\ttranslation along vector (i, j)\n");
    printf("\t-z m n\t\tscaling by factors m (x-axis) and n (y-axis)\n");
    printf("\t-r d  \t\trotation centered in O by a d degree angle\n");
    printf("\t-s d  \t\treflection over the axis passing through O ");
    printf("with an inclination\n");
    printf("\t      \t\tangle of d degrees\n");
    exit(0);
}
