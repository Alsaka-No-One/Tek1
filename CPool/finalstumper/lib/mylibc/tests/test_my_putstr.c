/*
** EPITECH PROJECT, 2018
** Kaminari | MyLibC - Tests | My Put String
** File description:
** Unit tests for my_putstr()
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylibc.h"

Test(__1_basic, str_is_null)
{
    char *str = NULL;

    cr_redirect_stdout();
    my_putstr(str);
    cr_assert_str_empty("", "Error on my_putstr().");
}

Test(__1_basic, str_is_not_null)
{
    char *str = "Hello World!";

    cr_redirect_stdout();
    my_putstr(str);
    cr_assert_stdout_eq_str("Hello World!", "Error on my_putstr().");
}
