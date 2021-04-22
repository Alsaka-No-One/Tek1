/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** unit_test_one
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lemin.h"
#include "struct.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(strlen, test_strlen)
{
    char str[] = "start";

    cr_assert_eq(my_strlen(str), 5);
}

Test(str_isnum, test_str_isnum)
{
    char str[] = "12";

    cr_assert_eq(my_str_isnum(str), 1);
}

Test(str_isnum, test_str_isnum_unv)
{
    char str[] = "24j";

    cr_assert_eq(my_str_isnum(str), 0);
}

Test(str_cpy, str_cpy, .init = redirect_all_std)
{
    char *str = malloc(sizeof(char) * 11);
    char msg[] = "23 #coucou";

    if (str == NULL)
        return;
    for (int i = 0; msg[i] != '\0'; i++)
        str[i] = msg[i];
    cr_assert_str_eq(my_strcpy(msg, str), "23 #coucou");
}