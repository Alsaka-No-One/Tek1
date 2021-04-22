/*
** EPITECH PROJECT, 2018
** Maths intersection | line
** File description:
** The function that returns the coordinate of a line
*/

#include "intersection.h"

coord_t *get_line_coord(coord_t point, coord_t vector, int t)
{
    coord_t line;

    line.x * t = point.x + t * vector.x;
    line.y * t = point.y + t * vector.y;
    line.z * t = point.z + t * vector.z;
    return (line);
}