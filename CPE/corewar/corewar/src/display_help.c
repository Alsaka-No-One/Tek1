/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** display_help
*/

#include <unistd.h>

void display_help(void)
{
    write(1, "USAGE\n", 6);
    write(1, "      ./corewar [-dump nbr_cycle] [[-n prog_number] ", 53);
    write(1, "[-a load_address] prog_name] ...\n", 34);
}