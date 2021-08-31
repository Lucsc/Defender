/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-brice.boualavong
** File description:
** lost_screen
*/

#include "defender.h"

button_s **create_butt(button_s **butt)
{
    butt = malloc(sizeof(button_s **) * 2);
    butt[0] = init_butt((sfVector2f){795, 568}, (sfVector2f){335, 130});
    butt[1] = init_butt((sfVector2f){877, 783}, (sfVector2f){155, 155});
    return butt;
}

void lostscreen(sfRenderWindow *window, music *damage)
{
    sfEvent event;
    object *bg = create_sprite("media/lstscreen.jpg", (sfVector2f){0, 0},
                                (sfIntRect){0, 0, 0, 0});
    button_s **butt = create_butt(butt);

    sfMusic_destroy(damage->music);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            analyse_endevents(window, butt, event);
        sfRenderWindow_clear(window, sfTransparent);
        sfRenderWindow_drawSprite(window, bg->sprite, NULL);
        sfRenderWindow_drawRectangleShape(window, butt[0]->shape, NULL);
        sfRenderWindow_drawRectangleShape(window, butt[1]->shape, NULL);
        sfRenderWindow_display(window);
    }
}

void analyse_endevents(sfRenderWindow *window, button_s **butt, sfEvent event)
{
    sfMouseButtonEvent click;
    sfVector2i hello = sfMouse_getPositionRenderWindow(window);
    sfVector2f goodbye;
    goodbye.x = hello.x;
    goodbye.y = hello.y;

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed) {
        restart_button(window, butt, goodbye);
        home_button(window, butt, goodbye);
    }
}

void restart_button(sfRenderWindow *window, button_s **butt, sfVector2f mouse)
{
    sfFloatRect hello = sfRectangleShape_getGlobalBounds(butt[0]->shape);
    const sfFloatRect *bibou = &hello;

    if (sfFloatRect_contains(bibou, mouse.x, mouse.y))
        gamescreen(window);
}

void home_button(sfRenderWindow *window, button_s **button, sfVector2f mouse)
{
    sfFloatRect hello = sfRectangleShape_getGlobalBounds(button[1]->shape);
    const sfFloatRect *bibou = &hello;

    if (sfFloatRect_contains(bibou, mouse.x, mouse.y))
        start_screen(window);
}