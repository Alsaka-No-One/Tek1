/*
** EPITECH PROJECT, 2019
** mlib
** File description:
** mlib header, create by Axel Virot
*/

#ifndef MLIB_H_
#define MLIB_H_

typedef enum mbool_e {
    false = 0,
    true = 1
} mbool;

//marg.c
char **marg(char *str, char c);
char **marg2(char *str);
void marg_free(char **arg);

//marray.c
int mrow(char **array);
void marr_free(char **array);

//marr_cp.c
int **marr_cp(char **arr, char **dest);
char **marr_cln(char **arr);

//mcond.c
int mis_num(char *str);
int mis_alpha(char *str);
int mis_alphanum(char *str);

//mconvertbase.c
char *mconvertbase(int nbr, int base);

//mgetline.c
char *mgetline();

//mgetnbr.c
int mgetnbr(char *str);

//mitoa.c
char *mitoa(int nbr);

//mputnbr.c
int mputnbr(int nb);

//mputstr.c
int mputchar(char c);
int mputstr(char *str);
int mputerr(char *str);
int mputarr(char **arr);

//mstrcat.c
char *mstrcat(char *str1, char *str2);

//mstrcmp.c
int mstrcmpltn(char *strl, char *strs);
int mstrcmp(char *str1, char *str2);
int mstrsame(char *str1, char *str2);

//mstr_cp.c
int mstr_cp(char const *str, char *dest);
char *mstr_cln(char const *str);

#endif /* MLIB_H_ */
