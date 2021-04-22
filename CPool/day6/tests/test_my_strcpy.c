/*
** EPITECH PROJECT, 2018
** test_my_strcpy
** File description:
** task1.5
*/

#include <criterion/criterion.h>

Test(my_strcpy, copy_string_in_empty_array)
{
    char dest[6] = {0};

    my_strcpy (dest, "Hello");
    cr_assert_str_eq (dest, "Hello");
}
