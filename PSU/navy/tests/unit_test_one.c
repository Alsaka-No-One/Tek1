/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** unit_test_one
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "navy.h"

Test(my_getnbr, test_my_getnbr)
{
    char test[3] = "15";

    cr_assert(my_getnbr(test) == 15);
}

Test(my_strlen, test_my_strlen)
{
    cr_assert(my_strlen("Hello World!") == 12);
}

Test(my_strisnum, test_my_strisnum)
{
    cr_assert(my_strisnum("bonjour") == 0);
}

Test(display_help, test_diplay_help)
{
    cr_assert(display_help() == 0);
}