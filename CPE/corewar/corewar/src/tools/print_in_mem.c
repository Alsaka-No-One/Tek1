/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** print_in_mem
*/

void print_in_mem(char *map, int index, int size, int nbr)
{
    if (size == -1)
        for (size = 0 ; map[index + size] == 0x00 ; size++);
    for ( ; size >= 0 ; size--) {
        map[index + size] = (nbr & 0xff);
        nbr = nbr >> 8;
    }
}