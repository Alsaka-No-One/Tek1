/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** dump_memory
*/

#include <unistd.h>
#include "op.h"
#include "corewar.h"

void print_mem(unsigned char c)
{
    char dispchar[16] = "0123456789ABCDEF";
    unsigned char result = c / 16;
    static int size = 0;

    if (result != 0) {
        size++;
        print_mem(result);
    }
    if (size == 0 && result == 0)
        write(1, "0", 1);
    size = 0;
    write(1, &dispchar[c % 16], 1);
}

int print_hexa(size_t c)
{
    char dispchar[16] = "0123456789ABCDEF";
    size_t result = c / 16;
    int size = 1;

    if (result != 0)
        size += print_hexa(result);
    write(1, &dispchar[c % 16], 1);
    return (size);
}

void add_space(int size)
{
    for ( ; size <= 3 ; size++)
        write(1, " ", 1);
}

void dump_memory(char *map)
{
    int size = 0;

    for (size_t i = 0 ; i < MEM_SIZE ; i++) {
        if (i % 32 == 0) {
            i != 0 ? write(1, "\n", 1) : 0;
            size = print_hexa(i);
            add_space(size);
            write(1, " : ", 3);
        }
        print_mem(map[i]);
        write(1, " ", 1);
    }
}