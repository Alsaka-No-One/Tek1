/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** load_champion
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "corewar.h"

enum {
    BUFF_SIZE = 10,
};

static char *load_champ_from_file(char *filename, size_t *size)
{
    char *temp = NULL;
    int fd = open(filename, O_RDONLY);
    char buff[BUFF_SIZE];
    size_t temp_size = 0;

    if (fd < 0)
        return (NULL);
    while ((temp_size = read(fd, buff, BUFF_SIZE)) > 0) {
        temp = my_strcat(temp, buff, *size, temp_size);
        *size += temp_size;
    }
    close(fd);
    return (temp);
}

static void init_champ_value(champion_t *champion)
{
    int i = 0;
    int value[][2] = {{0x01, 10}, {0x02, 5}, {0x03, 5}, {0x04, 10},
    {0x05, 10}, {0x06, 6}, {0x07, 6}, {0x08, 6}, {0x09, 20}, {0x0a, 25},
    {0x0b, 25}, {0x0c, 800}, {0x0d, 10}, {0x0e, 50}, {0x0f, 1000},
    {0x10, 2}};

    champion->pc = 0;
    champion->carry = 0;
    champion->verif = (verif_t){0, 0, 0};
    champion->is_dead = 0;
    for ( ; i < 17 ; i++)
        if (champion->code[0] == value[i][0])
            break;
    champion->wait_time = value[i][1];
    champion->reg[0] = champion->nb_player;
    for (int i = 1 ; i < REG_NUMBER ; i++)
        champion->reg[i] = 0;
}

static int load_champion_data(champion_t *champion)
{
    size_t size = 0;
    char *file_content = load_champ_from_file(champion->filename, &size);
    int index = 0;

    if (file_content == NULL) {
        my_put("Error with open: No such file or directory\n", 2);
        return (ERROR);
    }
    champion->name = get_champ_name(file_content, &index, size);
    if (champion->name == NULL)
        return (ERROR);
    champion->comment = get_champ_comment(file_content, &index, size);
    if (champion->comment == NULL)
        return (ERROR);
    champion->code = get_champ_code(file_content, &index, size);
    if (champion->code == NULL)
        return (ERROR);
    champion->code_size = size - index + 2;
    init_champ_value(champion);
    free(file_content);
    return (SUCCESS);
}

int load_champion(champion_t *champion)
{
    int nb_champion = 0;

    for ( ; champion[nb_champion].filename; nb_champion++);
    for (int i = 0 ; champion[i].filename ; i++) {
        if (load_champion_data(&champion[i]) == ERROR)
            return (ERROR);
    }
    return (SUCCESS);
}