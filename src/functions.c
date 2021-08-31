/*
** EPITECH PROJECT, 2021
** bsdefender
** File description:
** functions
*/

#include "defender.h"

button_s *init_butt(sfVector2f pos, sfVector2f size)
{
    button_s *butt = malloc(sizeof(button_s));

    if (butt == NULL)
        return NULL;
    butt->shape = sfRectangleShape_create();
    butt->position = pos;
    butt->size = size;
    sfRectangleShape_setSize(butt->shape, butt->size);
    sfRectangleShape_setPosition(butt->shape, butt->position);
    sfRectangleShape_setFillColor(butt->shape, sfTransparent);
    return butt;
}

button_s *init_buttons(const char *pathfile, sfVector2f pos,
sfVector2f size)
{
    button_s *butt = malloc(sizeof(button_s));

    if (butt == NULL)
        return NULL;
    butt->shape = sfRectangleShape_create();
    butt->position = pos;
    butt->size = size;
    butt->texture = sfTexture_createFromFile(pathfile, NULL);
    sfRectangleShape_setTexture(butt->shape, butt->texture, sfTrue);
    sfRectangleShape_setSize(butt->shape, butt->size);
    sfRectangleShape_setPosition(butt->shape, butt->position);
    return butt;
}

void moving_sprite(t *clock, object *bck_one, object *bck_two)
{
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->seconds = clock->time.microseconds / 1000000.0;
    if (clock->seconds > 0.09) {
        move_rect(&bck_one->rect, 240, 1438);
        move_rect(&bck_two->rect, 240, 1438);
        sfClock_restart(clock->clock);
    }
}