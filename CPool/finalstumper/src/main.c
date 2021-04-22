/*
** EPITECH PROJECT, 2018
** B-CPE-101 | C Pool Rush - Rush #3 | Final Stumper | Main
** File description:
** Main for Final Stumper
*/

#include "rush3.h"
#include "mylibc.h"

int error_management(char *buf)
{                               
    if (buf[0] != 'o' && buf[0] != '*' && buf[0] != 'A' && buf[0] != 'B'
        && buf[0] != '/') {
        my_putstr("none\n");
        return (84);
    }
    return (EXIT_SUCCESS);
}

void rush3(char *buf)
{
    check_rush(buf);
}

int main(void)
{
    char buf[BUF_SIZE + 1];
    int offset = 0;
    int len = 0;

    while ((len = read(0, buf + offset, BUF_SIZE - offset)) > 0)
        offset += len;
    buf[offset] = '\0';
    if (len < 0)
        return (84);
    if (error_management(buf) == 84)
        return (84);
    rush3(buf);
    return (EXIT_SUCCESS);
}
