/*
** EPITECH PROJECT, 2018
** MUL runner | draw_parallax
** File description:
** The functions to draw the parallax
*/

#include "runner.h"

void infinite_management(sprite_t *parallax1, sprite_t *p2, sfVector2f offset)
{
    p2->position.x += offset.x;
    if (p2->position.x <= 0) {
        parallax1->position.x = 0;
        p2->position.x = 1920;
        sfSprite_setPosition(parallax1->sprite, parallax1->position);
        sfSprite_setPosition(p2->sprite, p2->position);
    }
}

void draw_parallax(sfRenderWindow *window, game_t *g)
{
    sfVector2f offset;
    sfVector2f offset2;

    offset.x = -2;
    offset2.x = -1;
    sfSprite_setTexture(g->parallax1->sprite, g->parallax1->texture, sfTrue);
    sfSprite_setTexture(g->parallax2->sprite, g->parallax2->texture, sfTrue);
    sfSprite_setTexture(g->par2_2->sprite, g->par2_2->texture, sfTrue);
    sfSprite_setTexture(g->parallax3->sprite, g->parallax3->texture, sfTrue);
    sfSprite_setTexture(g->par3_2->sprite, g->par3_2->texture, sfTrue);
    infinite_management(g->parallax3, g->par3_2, offset);
    sfSprite_move(g->parallax3->sprite, offset);
    sfSprite_move(g->par3_2->sprite, offset);
    infinite_management(g->parallax2, g->par2_2, offset2);
    sfSprite_move(g->parallax2->sprite, offset2);
    sfSprite_move(g->par2_2->sprite, offset2);
    sfRenderWindow_drawSprite(window, g->parallax1->sprite, NULL);
    sfRenderWindow_drawSprite(window, g->parallax2->sprite, NULL);
    sfRenderWindow_drawSprite(window, g->par2_2->sprite, NULL);
    sfRenderWindow_drawSprite(window, g->parallax3->sprite, NULL);
    sfRenderWindow_drawSprite(window, g->par3_2->sprite, NULL);
}

void draw_parallax2(sfRenderWindow *window, game_t *g)
{
    sfVector2f offset;
    sfVector2f offset1;

    offset.x = -4;
    offset1.x = -6;
    sfSprite_setTexture(g->par->sprite, g->par->texture, sfTrue);
    sfSprite_setTexture(g->par1->sprite, g->par1->texture, sfTrue);
    sfSprite_setTexture(g->parallax5->sprite, g->parallax5->texture, sfTrue);
    sfSprite_setTexture(g->par5_2->sprite, g->par5_2->texture, sfTrue);
    infinite_management(g->par, g->par1, offset);
    infinite_management(g->parallax5, g->par5_2, offset1);
    sfSprite_move(g->par->sprite, offset);
    sfSprite_move(g->par1->sprite, offset);
    sfSprite_move(g->parallax5->sprite, offset1);
    sfSprite_move(g->par5_2->sprite, offset1);
    sfRenderWindow_drawSprite(window, g->par->sprite, NULL);
    sfRenderWindow_drawSprite(window, g->par1->sprite, NULL);
    sfRenderWindow_drawSprite(window, g->parallax5->sprite, NULL);
    sfRenderWindow_drawSprite(window, g->par5_2->sprite, NULL);
}