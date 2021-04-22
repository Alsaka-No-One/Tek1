/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** unit_test_tree
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lemin.h"
#include "struct.h"

void redirect_all_std(void);

Test(db_tab_len, db_tab_len, .init = redirect_all_std)
{
    char *arr[] = {"coucou", "len = 2", NULL};

    cr_assert_eq(double_tab_len(arr), 2);
}

Test(str_isnumalpha, str_isnumalpha, .init = redirect_all_std)
{
    cr_assert_eq(my_str_isalphanum("coucou23"), 1);
}

Test(str_isnumalpha, str_isnumalpha_unv, .init = redirect_all_std)
{
    cr_assert_eq(my_str_isalphanum("cou#cou23"), 0);
}

Test(get_str, get_str, .init = redirect_all_std)
{
    char *str = malloc(sizeof(char) * 11);
    char msg[] = "23 #coucou";

    if (str == NULL)
        return;
    for (int i = 0; msg[i] != '\0'; i++)
        str[i] = msg[i];
    cr_assert_str_eq(my_getstr(str), "23 #coucou");
}