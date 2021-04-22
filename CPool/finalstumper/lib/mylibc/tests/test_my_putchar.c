/*
** EPITECH PROJECT, 2018
** Kaminari | MyLibC - Tests | My Put Character
** File description:
** Units tests for my_putchar()
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylibc.h"

Test(__1_basic, return_write_value)
{
    char c = 'a';

    cr_redirect_stdout();
    my_putchar(c);
    cr_assert_stdout_eq_str("a", "Error on my_putchar().");
}
