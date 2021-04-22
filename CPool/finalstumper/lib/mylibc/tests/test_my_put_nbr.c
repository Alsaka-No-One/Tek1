/*
** EPITECH PROJECT, 2018
** Kaminari | MyLibC - Tests | My Put Number
** File description:
** Unit tests for my_putnbr()
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "mylibc.h"

Test(__1_basic, number_is_positive)
{
    int nb = 42;

    cr_redirect_stdout();
    cr_assert(my_put_nbr(nb) == 42);
}

Test(__1_basic, number_is_zero)
{
    int nb = 0;

    cr_redirect_stdout();
    cr_assert(my_put_nbr(nb) == 0);
}

Test(__1_basic, number_is_negative)
{
    int nb = -84;

    cr_redirect_stdout();
    my_put_nbr(nb);
    cr_assert_stdout_eq_str("-84", "Error on my_put_nbr().");
}
