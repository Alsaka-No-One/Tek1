/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** unit_test_two
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "navy.h"

Test(error_one, test_error_one)
{
    int status;

    cr_assert(error_input_processing() == 84);
    cr_assert(error_position_ships() == 84);
    cr_assert(error_pid() == 84);
    cr_assert(error_colision_ships() == 84);
    cr_assert(connection_failed() == 84);
    cr_assert(error_colision_ships() == 84);
    cr_assert(error_colision_ships() == 84);
}