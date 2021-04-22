/*
** EPITECH PROJECT, 2018
** Kaminari | MyLibC - Tests | My String Length
** File description:
** Unit tests for my_strlen()
*/

#include <criterion/criterion.h>
#include "mylibc.h"

Test(__1_basic, empty_string)
{
    char *str = NULL;

    cr_assert(my_strlen(str) == 0);
}

Test(__1_basic, string_hello_world)
{
    char *str = "Hello World!";

    cr_assert(my_strlen(str) == 12);
}
