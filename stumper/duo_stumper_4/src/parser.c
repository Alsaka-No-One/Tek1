/*
** EPITECH PROJECT, 2019
** stumper 4
** File description:
** parser
*/

#include "stumper.h"

static int check_open(DIR *rep)
{
    if (rep == NULL) {
        fprintf(stderr, "No such directory!\n");
        free(rep);
        return (ERROR);
    }
    return (SUCCESS);
}

static void fill_pokemon(fight_t *fight, char **array)
{
    int j = 0;
    int i = 0;

    for (; array[j] != NULL; j++) {
        if (com_or_not(array[j]) != 1)
            make_struct(fight, array[j], &i);
    }
}

static int make_read(fight_t *fight, struct stat sb, int fd)
{
    char *buffer = NULL;
    char **array = NULL;

    buffer = malloc(sizeof(char) * (sb.st_size + 2));
    if (buffer == NULL)
        return (ERROR);
    if (sb.st_size == 0) {
        free(buffer);
        return (ERROR);
    }
    if (read(fd, buffer, sb.st_size) < 0)
        return (ERROR);
    close(fd);
    printf("%s\n", buffer);
    array = st_to_ar(buffer);
    if (array == NULL)
        return (ERROR);
    fill_pokemon(fight, array);
    return (SUCCESS);
}

static int read_file(char *name, int *status, fight_t *fight)
{
    int fd;
    struct stat sb;

    name = mstrcat(name, "pokecfg/");
    fd = open(name, O_RDONLY);
    if (fd == -1) {
        *status = 84;
        return (ERROR);
    }
    if (stat(name, &sb) == -1) {
        *status = 84;
        return (ERROR);
    }
    if (make_read(fight, sb, fd) == ERROR) {
        *status = 84;
        return (ERROR);
    }
    return (SUCCESS);
}

int parser(char **argv, fight_t *fight)
{
    DIR *rep = NULL;
    struct dirent *rd = NULL;
    int status = 0;
    int turn = 1;

    rep = opendir("pokecfg/");
    if (check_open(rep) == ERROR)
        return (ERROR);
    rd = readdir(rep);
    while (rd != NULL && status != 84) {
        if (rd->d_name[0] != '.')
            turn = read_file(rd->d_name, &status, fight);
        if (turn == ERROR)
            return (ERROR);
        rd = readdir(rep);
    }
    free(rep);
    if (status == ERROR || turn == 1)
        return (ERROR);
    return (SUCCESS);
}
