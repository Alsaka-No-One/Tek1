/*
** EPITECH PROJECT, 2018
** CPE getnextline | get_next_line
** File description:
** The function that read and return a line of a file
*/

#include "get_next_line.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *new_str(char *save)
{
    char *new_save = NULL;
    int i = 0;

    if ((new_save = malloc(sizeof(char) * (my_strlen(save) + READ_SIZE + 2))) == NULL)
        return (NULL);
    while (save[i] != '\0') {
        new_save[i] = save[i];
        i++;
    }
    while (i != (my_strlen(save) + READ_SIZE + 1)) {
        new_save[i] = '\0';
        i++;
    }
    free(save);
    return (new_save);
}

char *reset(char *buffer)
{
    int i = 0;

    while (i < (READ_SIZE + 1)) {
        buffer[i] = '\0';
        i += 1;
    }
    return (buffer);
}

char *copy_str(char *buffer, char *save, int *i, int *j)
{
    while (buffer[*i] != '\0' && buffer[*i] != '\n') {
        save[*j] = buffer[*i];
        *i += 1;
        *j += 1;
    }
    save = new_str(save);
    return (save);
}

char *get_next_line(int fd)
{
    static char buffer[READ_SIZE + 1];
    char *save = NULL;
    static int i = 0;
    int check_finish = 1;
    int j = 0;

    if ((save = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
        return (NULL);
    for (int k = 0; k != (READ_SIZE + 1); k++)
        save[k] = '\0';
    while (check_finish >= 0 && buffer[i] != '\n') {
        if (!buffer[i]) {
            reset(buffer);
            check_finish = read(fd, buffer, READ_SIZE);
            i = 0;
            if (check_finish == 0) {
                return (NULL);
            }    
        } else if (buffer[i])
            save = copy_str(buffer, save, &i, &j);
    }
    i += 1;
    return (save);
}