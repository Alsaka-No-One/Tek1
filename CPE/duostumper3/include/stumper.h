/*
** EPITECH PROJECT, 2019
** stumper
** File description:
** header
*/

#ifndef STUMPER_H_
#define STUMPER_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int error_gestion(int argc, char **argv);
int crocus(char **av);
void fill_tab(char ***map, int height);
void write_0(char **show, char symp, int *pos);
void write_1(char **show, char symp, int *pos);
void write_2(char **show, char symp, int *pos);
void write_3(char **show, char symp, int *pos);
void write_4(char **show, char symp, int *pos);
void write_5(char **show, char symp, int *pos);
void write_6(char **show, char symp, int *pos);
void write_7(char **show, char symp, int *pos);
void write_8(char **show, char symp, int *pos);
void write_9(char **show, char symp, int *pos);
int find_symbol(int pos_string, char **av, int pos_nbrs, char **show);
int fill_show(char **av, int pos_nbrs, char **show, char symb);

#endif
