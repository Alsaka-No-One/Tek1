/*
** EPITECH PROJECT, 2018
** MUL my_hunter | event_management
** File description:
** Just the function to detect the left click
*/

#include "include/my_hunter.h"

void touch_condition(sfVector2i mouse_position, int comp_x, int comp_y, sprite_t *duck)
{
    if ((comp_x + 110 >= mouse_position.x && comp_x <= mouse_position.x)
        && (comp_y + 110 >= mouse_position.y && comp_y <= mouse_position.y)) {
        duck->position.x = -200;
        srand(time(NULL));
        duck->position.y = (rand() % (700 - 100 + 1)) + 100;
        duck->nb = manage_speed();
        sfSprite_setPosition(duck->sprite, duck->position);
        duck->score = duck->score + 10;
    }    
}

void handle_event(sfRenderWindow *window, sfEvent event, sprite_t *duck)
{
    sfVector2i mouse_position;
    int comp_x;
    int comp_y; 

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtMouseButtonPressed) {
            mouse_position = sfMouse_getPosition(window);
            comp_x = duck->position.x;
            comp_y = duck->position.y;
            touch_condition(mouse_position, comp_x, comp_y, duck);
        }
    }
}
