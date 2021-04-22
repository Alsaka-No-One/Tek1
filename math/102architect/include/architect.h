/*
** EPITECH PROJECT, 2018
** Maths | header file
** File description:
** header
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>

#ifndef __ARCHITECT_H__
#define __ARCHITECT_H__

typedef struct vector {
    float x;
    float y;
    float z;
} vector_t;

vector_t calcul_vector_result(vector_t, float **);
void disp_usage(void);
int my_str_eg(char *, char *);
vector_t get_vector(char *, char *);
void translation(float **, char *, char *);
void scaling(float **, char *, char *);
void rotation(float **, char *, char *);
void reflection(float **, char *, char *);
float **initialize_matrice(void);
float *vector_to_tab(vector_t);
void display_result(float **, vector_t, vector_t);
void mult_matrice(float **, float **);
void error_argument(int, char **);

#endif
