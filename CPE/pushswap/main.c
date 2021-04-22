/*
** EPITECH PROJECT, 2018
** CPE pushswap | main
** File description:
** The main functions
*/

#include "include/pushswap.h"

void add_element_list(list_t **list, int number)
{
    list_t *element;

    if ((element = malloc(sizeof(list_t))) == NULL)
        return;
    element->nb = number;
    for (int i = 0; i < NB_SIZE; i++)
        element->nbr[i] = '0';
    if (number < 0)
        number *= -1;
    for (int i = NB_SIZE - 1; number != 0; number /= 2, i--)
        if (number % 2 == 1)
            element->nbr[i] = '1';
    element->nbr[NB_SIZE] = '\0';
    element->next = *list;
    *list = element;
}

void pushswap_main(int argc, char **argv)
{
    list_t *list1 = NULL;
    list_t *list2 = NULL;
    int stop_condition;

    for (int i = argc - 1; i > 0; i--)
        add_element_list(&list1, my_getnbr(argv[i]));
    stop_condition = position(&list1);
    if (argc == 3)
        easy_sort(&list1, &list2, 0);
    else if (argc > 3) {
        if (check_sort(&list1) == 0) {
            write(1, "\n", 1);
            return;
        }
        algo(&list1, &list2, stop_condition, argc);
        separate_list(&list1, &list2, argc);
        write(1, "sa sa\n", 6);
    }
    free(list1);
    free(list2);
}

int main(int argc, char **argv)
{
    if (argc < 2 || argc >= 7500)
        return (84);
    else {
        if (error_argument(argc, argv) == 84)
            return (84);
        pushswap_main(argc, argv);
        if (argc == 2)
            write(1, "\n", 1);
        return (0);
    }
}
