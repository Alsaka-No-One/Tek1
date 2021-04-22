/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** input_processing
*/

#include "lemin.h"
#include "struct.h"

int input_processing(int argc, char **argv)
{
    if (argc != 1)
        return (ERROR);
    else
        return (parse_file());
}