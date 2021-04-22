/*
** EPITECH PROJECT, 2019
** stumper
** File description:
** usefull functions
*/

#include "stumper.h"

int com_or_not(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (i == 0 && str[i] == '#')
            return (1);
        else if (str[i] == '#')
            return (SUCCESS);
        i++;
    }
    return (SUCCESS);
}

char *mstrcat(char *dest, char *src)
{
    int i = 0;
    char *new_dest = malloc(sizeof(char) * (strlen(dest) + strlen(src) + 1));

    if (new_dest == NULL)
        return (NULL);
    for (; src[i] != '\0'; i++)
        new_dest[i] = src[i];
    for (int j = 0; dest[j] != '\0'; j++) {
        new_dest[i] = dest[j];
        i++;
    }
    new_dest[i] = '\0';
    return (new_dest);
}

static void make_struct2(fight_t *fight, char *str, int *i, int k)
{
    char speed[6];
    char health[6];

    for (int j = 0; str[k] != ';'; j++, k++)
        speed[j] = str[k];
    fight->list[*i].speed = atoi(speed);
    k++;
    for (int j = 0; str[k] != '\0'; j++, k++)
        health[j] = str[k];
    fight->list[*i].health = atoi(speed);
    *i += 1;
}

void make_struct(fight_t *fight, char *str, int *i)
{
    char *name = malloc(sizeof(char) * 20);
    char attack[5];
    char defense[5];
    int k = 0;

    printf("ici?\n");
    for (int j = 0; str[k] != ';'; j++, k++) {
        printf("%s\n", str);
        fight->list[*i].name[j] = str[k];
    }
    k++;
    printf("?\n");
    for (int j = 0; str[k] != ';'; j++, k++)
        attack[j] = str[k];
    fight->list[*i].attack = atoi(attack);
    k++;
    printf("ikdqfsjkldqsjflkjqsfdi?\n");
    for (int j = 0; str[k] != ';'; j++, k++)
        defense[j] = str[k];
    fight->list[*i].defense = atoi(defense);
    k++;
    make_struct2(fight, str, i, k);
}
