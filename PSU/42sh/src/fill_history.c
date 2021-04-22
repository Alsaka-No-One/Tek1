/*
** EPITECH PROJECT, 2019
** 42sf
** File description:
** fill the history
*/

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "mlib.h"
#include "minishell.h"

static char *mtime(void)
{
    char *buffer = NULL;
    time_t timestamp = time(NULL);
    struct tm *t = localtime(&timestamp);
    int i = 0;

    buffer = malloc(sizeof(char *) * 6);
    if (t->tm_hour < 10)
        buffer[i++] = ' ';
    buffer[i++] = '\0';
    strcat(buffer, mitoa(t->tm_hour));
    strcat(buffer, ":");
    for ( ; buffer[i] ; i++);
    if (t->tm_min < 10)
        buffer[i++] = '0';
    buffer[i++] = '\0';
    strcat(buffer, mitoa(t->tm_min));
    return (buffer);
}

static void fill_history_line(data_t *data, char *line, char *input)
{
    int row = 0;
    int space = 0;

    space = 6 - strlen(mitoa(data->history_index));
    for (int i = 0 ; i < space ; i++)
        line[row++] = ' ';
    line[row] = '\0';
    strcat(line, mitoa(data->history_index));
    strcat(line, "  ");
    strcat(line, mtime());
    strcat(line, "   ");
    strcat(line, input);
    for (int i = 0 ; line[i] ; i++)
        if (line[i] == '\n')
            line[i] = '\0';
}

static mbool same_command(char *str1, char *str2)
{
    char *temp1 = NULL;
    char *temp2 = NULL;

    if (!str1 || !str2)
        return (false);
    temp1 = mstr_cln(str1);
    temp2 = mstr_cln(str2);
    for (int i = 0 ; i < 16 ; i++) {
        temp1[i] = ' ';
        temp2[i] = ' ';
    }
    if (mstrsame(temp1, temp2) == true) {
        free(temp1);
        free(temp2);
        return (true);
    }
    free(temp1);
    free(temp2);
    return (false);
}

void fill_history(char *input, data_t *data)
{
    char *line = malloc(sizeof(char *) * (18 + strlen(input)));

    if (!line)
        return;
    fill_history_line(data, line, input);
    if (data->history_index == MAX_HISTORY)
        initialize_history(data);
    if (data->history[data->history_index])
        free(data->history[data->history_index]);
    for (int i = 0 ; i < data->history_index ; i++)
        if (same_command(data->history[i], line) == true)
            data->history[i] = NULL;
    data->history[data->history_index++] = mstr_cln(line);
    if (line)
        free(line);
}
