/*
** EPITECH PROJECT, 2018
** Maths intersection | equation
** File description:
** the functions that return the solutions of the equation
*/

#include "intersection.h"

void result_equation(float a, float b, float c, char **argv)
{
    int delta = pow(b, 2) - 4 * a * c;
    float result1;
    float result2;

    if (delta < 0)
        printf("No intersection point.\n");
    if (delta == 0) {
        result1 = -b / (2 * a);
        printf("1 intersection point:\n");
        printf("(%.3f, %.3f, %.3f)\n", atof(argv[2]) + result1 * atof(argv[5]), atof(argv[3]) + result1 * atof(argv[6]), atof(argv[4]) + result1 * atof(argv[7]));
    } else if (delta > 0) {
        printf("2 intersection points:\n");
        result1 = (-b + sqrt(delta)) / (2 * a);
        result2 = (-b - sqrt(delta)) / (2 * a);
        printf("(%.3f, %.3f, %.3f)\n", atof(argv[2]) + result1 * atof(argv[5]), atof(argv[3]) + result1 * atof(argv[6]), atof(argv[4]) + result1 * atof(argv[7]));
        printf("(%.3f, %.3f, %.3f)\n", atof(argv[2]) + result2 * atof(argv[5]), atof(argv[3]) + result2 * atof(argv[6]), atof(argv[4]) + result2 * atof(argv[7]));
    }
}
