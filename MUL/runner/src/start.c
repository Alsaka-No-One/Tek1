/*
** EPITECH PROJECT, 2019
** MUL runner | start
** File description:
** The function to the beginning of the program
*/

#include "runner.h"

game_t *initialize_struct(game_t *g)
{
    g->character = initialize_character(g->character);
    g->foreground = initialize_foreground(g->foreground);
    g->parallax1 = initialize_parallax(g->parallax1, "ressources/plx-1.png");
    g->parallax2 = initialize_parallax(g->parallax2, "ressources/plx-2.png");
    g->parallax3 = initialize_parallax(g->parallax3, "ressources/plx-3.png");
    g->par = initialize_parallax(g->par, "ressources/plx-4.png");
    g->parallax5 = initialize_parallax(g->parallax5, "ressources/plx-5.png");
    g->par1 = initialize_infinite(g->par1, "ressources/plx-4.png");
    g->par5_2 = initialize_infinite(g->par5_2, "ressources/plx-5.png");
    g->par2_2 = initialize_infinite(g->par2_2, "ressources/plx-2.png");
    g->par3_2 = initialize_infinite(g->par3_2, "ressources/plx-3.png");
    g->for2 = initialize_infinite2(g->for2, "ressources/foreground.png");
    g->jb = initialize_infinite(g->jb, "ressources/jb-tree.png");
    return (g);
}
