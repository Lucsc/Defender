/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** help
*/

#include "defender.h"

void gohelp(sfRenderWindow *window, sfEvent event, button_s *button)
{
    sfMouseButtonEvent click;
    sfVector2i hello = sfMouse_getPositionRenderWindow(window);
    sfVector2f goodbye;
    goodbye.x = hello.x;
    goodbye.y = hello.y;

    if (event.type == sfEvtMouseButtonPressed)
        button_help(button, goodbye, window);
}

void analyse_eventshelp(sfRenderWindow *window, sfEvent event, button_s *quit)
{
    sfMouseButtonEvent click;
    sfVector2i hello = sfMouse_getPositionRenderWindow(window);
    sfVector2f goodbye;
    goodbye.x = hello.x;
    goodbye.y = hello.y;

    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
    if (event.type == sfEvtMouseButtonPressed)
        button_leave(quit, goodbye, window);
}

void helpwindow(void)
{
    sfVideoMode video_mode = {890, 500, 32};
    sfRenderWindow *window =
    sfRenderWindow_create(video_mode, "My_window", sfResize | sfClose, NULL);
    sfEvent event;
    object *bgmain = create_sprite("media/howto.jpg", (sfVector2f){0, 0},
                                    (sfIntRect){0, 0, 0, 0});
    button_s *quit = init_buttons("media/quit.png", (sfVector2f){775, 10},
                                    (sfVector2f){110, 111});

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            analyse_eventshelp(window, event, quit);
        sfRenderWindow_clear(window, sfTransparent);
        sfRenderWindow_drawSprite(window, bgmain->sprite, NULL);
        sfRenderWindow_drawRectangleShape(window, quit->shape, NULL);
        sfRenderWindow_display(window);
    }
    free(bgmain);
    return;
}