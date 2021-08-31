/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** pause
*/

#include "defender.h"

button_s **createbuttonpause(button_s **button)
{
    button = malloc(sizeof(button_s **) * 4);
    button[0] = init_butt((sfVector2f){795, 527}, (sfVector2f){270, 80});
    button[1] = init_butt((sfVector2f){795, 425}, (sfVector2f){270, 80});
    button[2] = init_butt((sfVector2f){795, 325}, (sfVector2f){270, 80});
    button[3] = init_butt((sfVector2f){890, 625}, (sfVector2f){80, 80});
    return (button);
}

int analypause(sfRenderWindow *window, object **game, object *p, button_s **b)
{
    sfMouseButtonEvent click;
    sfVector2i hello = sfMouse_getPositionRenderWindow(window);
    sfVector2f goodbye;
    goodbye.x = hello.x;
    goodbye.y = hello.y;

    if (game[0]->event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (game[0]->event.type == sfEvtKeyPressed)
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            return (2);
    if (game[0]->event.type == sfEvtMouseButtonPressed) {
        button_leave(b[0], goodbye, window);
        button_is_clicked(b[1], goodbye, window);
        if (button_resume(b[2], goodbye, window) == 2)
            return (2);
        button_home(b[3], goodbye, window);
    }
    return (0);
}

void drawpause(sfRenderWindow *window, object **game, object *p, button_s **b)
{
    sfRenderWindow_drawSprite(window, game[0]->sprite, NULL);
    for (int i = 6; game[i] != NULL; i++)
        sfRenderWindow_drawSprite(window, game[i]->sprite, NULL);
    sfRenderWindow_drawSprite(window, game[4]->sprite, NULL);
    sfRenderWindow_drawSprite(window, game[5]->sprite, NULL);
    for (int i = 1; i <= 3; i++)
        sfRenderWindow_drawSprite(window, game[i]->sprite, NULL);
    sfRenderWindow_drawSprite(window, p->sprite, NULL);
    for (int i = 0; i <= 3; i++)
        sfRenderWindow_drawRectangleShape(window, b[i]->shape, NULL);
    sfRenderWindow_display(window);
}

int pausescreen(sfRenderWindow *window, object **game,
                button_s **life, button_s **zone)
{
    object *pauseb = create_sprite("media/pause.png", (sfVector2f){750, 200},
                                        (sfIntRect){0, 0, 0, 0});
    button_s **button = createbuttonpause(button);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &game[0]->event))
            if (analypause(window, game, pauseb, button) == 2)
                return (0);
        drawpause(window, game, pauseb, button);
    }
}

void go_pause(sfRenderWindow *window, object **game,
                button_s **life, button_s **zone)
{
    if (game[0]->event.type == sfEvtKeyPressed)
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            pausescreen(window, game, zone, life);
}