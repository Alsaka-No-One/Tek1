/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** unit_test_two
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lemin.h"
#include "struct.h"

void redirect_all_std(void);

Test(put_str, put_str, .init = redirect_all_std)
{
    my_putstr("Coucou");
    cr_assert_stdout_eq_str("Coucou");
}

Test(put_nbr, put_nbr, .init = redirect_all_std)
{
    my_put_nbr(23);
    cr_assert_stdout_eq_str("23");
}

Test(get_nbr, get_nbr, .init = redirect_all_std)
{
    cr_assert_eq(my_getnbr("23"), 23);

}

Test(check_com, check_com, .init = redirect_all_std)
{
    char *str = malloc(sizeof(char) * 11);
    char msg[] = "23 #coucou";

    if (str == NULL)
        return;
    for (int i = 0; msg[i] != '\0'; i++)
        str[i] = msg[i];
    cr_assert_str_eq(check_com(str), "23 ");
}

Test(com_or_not, com_or_not, .init = redirect_all_std)
{
    cr_assert_eq(com_or_not("#coucou"), 1);
}