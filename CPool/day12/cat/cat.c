/*
** EPITECH PROJECT, 2018
** cat
** File description:
** reprogram cat
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <../include/my.h>

char *cat(int ac, char *av)
{
    int fd;
    char *buffer[30000];
    int i = 1;
    int size;

    while (i != ac) {
        fd = open (av[i]  O_RDONLY);
        if (fd == -1)
            return(84);
        my_putstr (fd);
        my_putchar ('\n');
        size =  read (fd, buffer, 29999);
        my_putnbr (size);
        my_putchar ('\n');
        close (fd);
        i++;
    }
    return (0);    
}
