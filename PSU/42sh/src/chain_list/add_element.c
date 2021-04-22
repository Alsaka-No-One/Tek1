/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** add_element
*/

#include <string.h>
#include <stdlib.h>
#include "mlib.h"
#include "minishell.h"

int add_element(list_t **list, char *command)
{
    list_t *element = NULL;

    element = malloc(sizeof(list_t));
    if (element == NULL || !command)
        return (ERROR);
    element->command = mstr_cln(command);
    if (element->command == NULL)
        return (ERROR);
    element->next = *list;
    *list = element;
    return (SUCCESS);
}