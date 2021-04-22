/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** load_value
*/

#include <stdlib.h>
#include "corewar.h"

static void take_register(char *map, int *index, mem_value_t *value, int type)
{
    if ((type & T_REG) != T_REG) {
        value->type = -1;
        value->value = -1;
        return;
    }
    value->type = T_REG;
    value->value = bytes_to_int(map, *index, T_REG);
    (*index) += T_REG;
}

static void take_direct(char *map, int *index, mem_value_t *value, int type)
{
    if ((type & T_DIR) == T_DIR) {
        value->type = T_DIR;
        value->value = bytes_to_int(map, *index, T_DIR);
        (*index) += T_DIR;
    } else if ((type & T_SHORTDIR) == T_SHORTDIR) {
        value->type = T_SHORTDIR;
        value->value = bytes_to_int(map, *index, 2);
        (*index) += 2;
    } else {
        value->type = -1;
        value->value = -1;
    }
}

static void take_indirect(char *map, int *index, mem_value_t *value, int type)
{
    if ((type & T_IND) != T_IND) {
        value->type = -1;
        value->value = -1;
        return;
    }
    value->type = T_IND;
    value->value = bytes_to_int(map, *index, T_IND);
    (*index) += T_IND;
}

int load_value(char *map, int index, mem_value_t **value, int *type)
{
    int coding_byte = map[index];
    int mem_index = index + 1;
    mem_value_t *temp = malloc(sizeof(mem_value_t) * MAX_ARGS_NUMBER);

    if (temp == NULL)
        return (ERROR);
    for (int i = 0 ; i < MAX_ARGS_NUMBER ; i++) {
        temp[i].value = -1;
        temp[i].type = -1;
    }
    for (int i = 0 ; i < MAX_ARGS_NUMBER ; i++) {
        coding_byte = map[index] >> (MAX_ARGS_NUMBER - 1 - i) * 2;
        if ((coding_byte & B_REG) == B_REG)
            take_register(map, &mem_index, &temp[i], type[i]);
        if ((coding_byte & B_DIR) == B_DIR)
            take_direct(map, &mem_index, &temp[i], type[i]);
        if ((coding_byte & B_IND) == B_IND)
            take_indirect(map, &mem_index, &temp[i], type[i]);
    }
    *value = temp;
    return (SUCCESS);
}