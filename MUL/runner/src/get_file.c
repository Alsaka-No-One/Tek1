/*
** EPITECH PROJECT, 2018
** BSQ | open file
** File description:
** A function that open a file
*/

#include "runner.h"

char **fs_print_file(char const *filepath)
{
    FILE *file = fopen(filepath, "r");
    size_t buffer_size = 100;
    char *buffer = malloc(sizeof(char) * 101);
    char **map = malloc(sizeof(char *) * 6);

    if (file == NULL) {
        my_putstr("Error with open! Check the file!\n");
        return (NULL);
    }
    for (int i = 0; i <= 4; i++) {
        map[i] = malloc(sizeof(char) * 100);
        getline(&buffer, &buffer_size, file);
        my_strcpy(buffer, map[i]);
    }
    fclose(file);
    return (map);
}