/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** shell
*/

#ifndef SHELL_H_
#define SHELL_H_

static const int ERROR = 84;
static const int SUCCESS = 0;
static const int STOP = -84;

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

typedef struct func_s {
    int (*fptr)(char **arg, char ***envp);
    char name[100];
} func_t;

int my_strlen(char const *str);
void my_putstr(char const *str);
int minishell(char **envp);
int arg_gestion(int argc, char **argv, char **envp);
int my_strcomp(char const *str, char const *str_comp);
int get_command(func_t *tab, char **arg, char ***envp);
int my_getnbr(char const *str);
int my_exit(char **arg);
char **string_to_arg(char *buff);
void free_tab(char **tab);
int make_cd(char **arg, char ***envp);
int make_setenv(char **arg, char ***envp);
int make_unsetenv(char **arg, char ***envp);
int make_env(char **arg, char ***envp);
int analyse_exec(char **arg, char **envp);
int display_invalid_command(char **arg);
int my_exec(char **arg, char **envp);
int find_path(char **arg, char **envp);
char *my_strcpy(char *dest, char *src);
char *my_strcpy_env(char *dest, char *src);
char *my_strcpy_double(char *dest, char *src, char *second);
char **get_env(char **envp);
char *realloc_str(char *str, int nb);
char *my_strcat_path(char *dest, char *src);
char **string_to_arg2(char **arg, int i_tab, int j_tab);
int my_strcomp_env(char const *str, char const *str_comp);
int compt_array(char **array);
char **my_realloc(char **tab);

#endif
