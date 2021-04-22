/*
** EPITECH PROJECT, 2019
** label
** File description:
** analyse
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "op.h"
#include "asm.h"

char *sp_l(char const *str1)
{
    int i = 0;
    int u = 0;

    char *nstr1 = malloc(sizeof(char) * (my_strlen(str1) + 1));
    for (; str1[i] && str1[i] == ' '; i++);
    for (; str1[i + u]; u++)
        nstr1[u] = str1[i + u];
    nstr1[u] = '\0';
    return (nstr1);
}

int analyse_l2(char *spl)
{
    if (spl[0] == '\n') {
        free(spl);
        return (1);
    }
    if (spl[0] == COMMENT_CHAR) {
        free(spl);
        return (1);
    }
    return (0);
}

void analyse_l3(check_t *check, char *file, int i)
{
    (check->n < 1) ? error_n(file, i) : 0;
    (check->c < 1) ? error(file, i, 5, 0) : 0;
    (check->c > 1) ? error(file, i, 6, 0) : 0;
}

void analyse_l(char *line, char *file, check_t *check, int i)
{
    char *spl = sp_l(line);

    (check->n > 1) ? error(file, i, 4, 0) : 0;
    if (analyse_l2(spl))
        return;
    if (my_strcmp(spl, NAME_CMD_STRING)) {
        (my_strlen(line) > 136) ? error(file, i, 9, 0) : 0;
        check->n++;
        free(spl);
        return;
    }
    if (my_strcmp(spl, COMMENT_CMD_STRING)) {
        (my_strlen(line) > 2059) ? error(file, i, 12, 0) : 0;
        (check->n < 1) ? error(file, i, 3, 0) : 0;
        check->c++;
        free(spl);
        return;
    }
    analyse_l3(check, file, i);
    free(spl);
}

char **analyse(char **map, char *filename)
{
    check_t check = {0, 0};
    char **cmds;

    TOTAL_FILE = map;
    for (int i = 0; map[i] != NULL; i++)
        analyse_l(map[i], filename, &check, i);
    cmds = verif_command(map, filename);
    TOTAL_CMDS = cmds;
    return (cmds);
}