/*
** EPITECH PROJECT, 2019
** Maths | header
** File description:
** header
*/

#ifndef TORUS_H_
#define TORUS_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct torus_s {
    float a4;
    float a3;
    float a2;
    float a1;
    float a0;
    int n;
} torus_t;

typedef struct interv_s {
    float xmin;
    float xmax;
    int return_value;
} interv_t;

float solvefx(torus_t f, float x);
float solvef2x(torus_t f, float x);
void newton(torus_t f);
void help_usage(void);
interv_t secant_method(torus_t, interv_t);
void bisection_function(torus_t function);
void secant(torus_t);

#endif /* !TORUS_H_ */
