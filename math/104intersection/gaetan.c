/*
** EPITECH PROJECT, 2018
** Maths 104architect | main
** File description:
** The main function
*/

#include "intersection.h"

int architect_main(int argc, char **argv){
    int calc = atoi(argv[1]);
    coord_t point;
    int radius = atoi(argv[argc - 1]);

    if (calc == 1) {
        printf("Sphere of radius %d\n", radius);
        point = form_sphere(argv);
    } else if (calc == 2) {
        printf("Cylinder of radius %d\n", radius);
        point = form_cylinder(argv);
    } else if (calc == 3) {
        printf("Cone with a %d degree angle\n", radius);
        point = form_cone(argv, atoi(argv[argc - 1]));
    } else
        return (84);
    printf("Line passing through the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)\n", atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), atoi(argv[7]));
    if (point.x == 0 && point.y == 0 && point.z == 0) {
        printf("There is an infinite number of intersection points.\n");
        return (0);
    }
    result_equation(point.x, point.y, point.z, argv);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            print_usage();
            return (0);
        }
    }
    if (check_argument(argc, argv) != 0)
        return (84);
    architect_main(argc, argv);
    return (0);
}
