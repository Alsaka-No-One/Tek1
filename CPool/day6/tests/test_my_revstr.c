/*
** EPITECH PROJECT, 2018
** test_my_revstr
** File description:
** Test Task3.5
*/

#include <criterion/criterion.h>

Test(my_revstr, return_value_is_reversed)
{
    char str[6] = {0};
    
    strcpy (str, "hello");
    cr_assert_str_eq(my_revstr (str), "olleH");
}
