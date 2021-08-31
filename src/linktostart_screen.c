/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** norme
*/

#include "defender.h"

void drawstartscreen(button_s **info, object **bgmain, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfTransparent);
    sfRenderWindow_drawSprite(window, bgmain[0]->sprite, NULL);
    sfRenderWindow_drawSprite(window, bgmain[1]->sprite, NULL);
    for (int i = 0; i <= 2; i++)
        sfRenderWindow_drawRectangleShape(window, info[i]->shape, NULL);
    sfRenderWindow_display(window);
}

button_s **buttonstart(button_s **info)
{
    info = malloc(sizeof(button_s **) * 3);
    info[0] = init_buttons("media/start.png", (sfVector2f){500, 680},
                            (sfVector2f){112, 112});
    info[1] = init_buttons("media/info.png", (sfVector2f){900, 680},
                            (sfVector2f){123, 115});
    info[2] = init_buttons("media/quit.png", (sfVector2f){1300, 680},
                            (sfVector2f){110, 111});
    return (info);
}

object **objectstart(object **bgmain)
{
    bgmain = malloc(sizeof(object **) * 2);
    bgmain[0] = create_sprite("media/bgmain.jpg", (sfVector2f){0, 0},
                                (sfIntRect){0, 0, 0, 0});
    bgmain[1] = create_sprite("media/logo.png", (sfVector2f){700, 100},
                                (sfIntRect){0, 0, 0, 0});
    return (bgmain);
}

button_s **gamebutton(button_s **tower)
{
    tower = malloc(sizeof(button_s **) * 5);
    tower[0] = init_butt((sfVector2f){1685, 299}, (sfVector2f){70, 127});
    tower[1] = init_butt((sfVector2f){1813, 319}, (sfVector2f){84, 104});
    tower[2] = init_butt((sfVector2f){1668, 543}, (sfVector2f){86, 160});
    tower[3] = init_butt((sfVector2f){1822, 542}, (sfVector2f){83, 161});
    return (tower);

}

void drawscreen(button_s **tower, sfRenderWindow *window)
{
    for (int i = 0; i <= 3; i++)
        sfRenderWindow_drawRectangleShape(window, tower[i]->shape, NULL);
}