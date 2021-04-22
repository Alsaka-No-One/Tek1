/*
** EPITECH PROJECT, 2018
** Maths 104intersection | header
** File description:
** The header
*/

#ifndef INTERSECTION_H_
#define INTERSECTION_H_

#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

typedef struct coord_s {
    float x;
    float y;
    float z;
} coord_t;

void result_equation(float a, float b, float c, char **argv);
int check_argument(int argc, char** argv);
void print_usage(void);
coord_t *get_line_coord(coord_t *, coord_t *, int);
coord_t form_sphere(char **argv);
coord_t form_cylinder(char **argv);
coord_t form_cone(char **argv, int angle);

#endif 
