/*
** EPITECH PROJECT, 2018
** CPE BSQ | main
** File description:
** Just the main
*/

#include "include/bsq.h"

void bsq_main(char *buffer, char **argv, int nb_linum)
{
    char *dest = malloc(sizeof(char) * my_strlen(buffer));
    int nb_cols;
    char **tab;
    int **map;
    int linum;
    int cols;
    int nb;

    if (dest == NULL)
        exit(84);
    dest = pass_the_first_line(buffer);
    nb_cols = find_nb_cols(dest);
    tab = string_to_tab(dest, nb_linum, nb_cols, tab);
    map = create_tab_rev_dem(tab, nb_linum, nb_cols, map);
    modif_tab_into_dem(map, nb_linum, nb_cols);
    nb = get_the_biggest_number(map, nb_linum, nb_cols);
    linum = get_the_linum(map, nb_linum, nb_cols, nb);
    cols = get_the_cols(map, nb_linum, nb_cols, nb);
    draw_the_square(tab, linum, cols, nb);
    print_tab(tab, nb_linum, nb_cols);
}

int main(int argc, char **argv)
{
    char *buffer;
    int nb_linum;

    if (argc != 2)
        return (84);
    buffer = fs_print_file(argv[1], buffer);
    nb_linum = my_getnbr(buffer);
    if (nb_linum <= 0)
        return (84);
    bsq_main(buffer, argv, nb_linum);
    free(buffer);
    return (0);
}
