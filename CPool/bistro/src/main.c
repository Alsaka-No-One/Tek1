#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistromatic.h"

void my_putchar(char c)
{
    write (1, &c, 1);
}

void  my_putstr(char const *str)
{
    int compt;

    compt = 0;
    while (str[compt] != '\0' ){
        my_putchar (str[compt]);
        compt =  compt + 1;
    }
}

int   my_strlen(char const *str);
/*{
    int turn;
    int compt;

    turn = 0;
    while (str[turn] != '\0'){
        turn = turn + 1;
    }
    return (turn);
    }*/

int   my_atoi(char const *str)
{
    int i = 0;
    long nb = 0;
    int signe = 1;

    while ((str[i] != '-') && (str[i] < '0') || (str[i] > '9') && (str[i] != '+')){
        i++;
    }
    while (str[i] == '+' || str[i] == '-'){
        signe = str[i];
        i++;
    }
    if(signe == '-')
        signe = -1;
    else
        signe = 1;
    while (str[i] && str[i] >= '0' && str[i] <= '9'){
        nb = nb * 10 + (str[i] - 48);
        if ((signe == -1 && nb > 2147483648) || (signe == 1 && nb > 2147483647))
            return(0);
        i++;
    }
    return(nb * signe);
}
static char  *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

static void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

static void check_base(char const *b)
{
    if (my_strlen(b) != 10) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

int             main(int ac, char **av)
{
    unsigned int size;
    char *expr;

    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+_*/%\" exp_len\n");
        return (EXIT_USAGE);
    }
    check_base(av[1]);
    check_ops(av[2]);
    size = my_atoi(av[3]);
    expr = get_expr(size);
    my_putstr(eval_expr(av[1], av[2], expr, size));
    return (EXIT_SUCCESS);
}
