/*
** EPITECH PROJECT, 2019
** -h
** File description:
** -h
*/

#include "torus.h"

void help_usage(void)
{
    printf("\033[32mUSAGE\033[0m\n");
    printf("    ./105torus opt a0 a1 a2 a3 a4 n\n");
    printf("\n");
    printf("\033[35mDESCRIPTION\033[0m\n");
    printf("    \033[34mopt\033[0m        method option:\n");
    printf("                   1 for the bissection method\n");
    printf("                   2 for Newton's method\n");
    printf("                   3 for the secant method\n");
    printf("    \033[31ma[0-4]\033[0m     coefficients of the equation\n");
    printf("    \033[36mn\033[0m          precision (the application of the polynomial to the solution should\n");
    printf("               be smaller than 10^⁻n");
}