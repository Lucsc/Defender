/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-brice.boualavong
** File description:
** linked_togame_screen
*/

#include "defender.h"

void eventsgame(sfRenderWindow *window, object **game,
                        button_s **tow, button_s **zone)
{
    sfMouseButtonEvent click;
    sfVector2i hello = sfMouse_getPositionRenderWindow(window);
    sfVector2f goodbye;
    goodbye.x = hello.x;
    goodbye.y = hello.y;
    int r = game[0]->i;

    if (game[0]->event.type == sfEvtMouseButtonPressed) {
        if (game[3]->b >= 42) {
            game[0]->i = towertopleft(tow[0], goodbye, window, game[0]->i);
            game[0]->i = towertopright(tow[1], goodbye, window, game[0]->i);
            game[0]->i = towerdownleft(tow[2], goodbye, window, game[0]->i);
            game[0]->i = towerdownright(tow[3], goodbye, window, game[0]->i);
        }
    }
    if (r != game[0]->i)
        game[3]->b -= 42;
}

button_s **all_zone(button_s **zone)
{
    zone = malloc(sizeof(button_s ** ) * 11);
    zone[0] = init_butt((sfVector2f){210, 400}, (sfVector2f){80, 80});
    zone[1] = init_butt((sfVector2f){210, 680}, (sfVector2f){80, 80});
    zone[2] = init_butt((sfVector2f){575, 800}, (sfVector2f){80, 80});
    zone[3] = init_butt((sfVector2f){575, 500}, (sfVector2f){80, 80});
    zone[4] = init_butt((sfVector2f){400, 200}, (sfVector2f){80, 80});
    zone[5] = init_butt((sfVector2f){680, 200}, (sfVector2f){80, 80});
    zone[6] = init_butt((sfVector2f){910, 400}, (sfVector2f){80, 80});
    zone[7] = init_butt((sfVector2f){910, 680}, (sfVector2f){80, 80});
    zone[8] = init_butt((sfVector2f){1210, 535}, (sfVector2f){80, 80});
    zone[9] = init_butt((sfVector2f){1210, 200}, (sfVector2f){80, 80});
    zone[10] = init_butt((sfVector2f){1350, 950}, (sfVector2f){250, 55});
    return (zone);

}

void drawzones(button_s **zone, sfRenderWindow *window)
{
    for (int i = 0; i <= 9; i++)
        if (zone[i]->shape != NULL)
            sfRenderWindow_drawRectangleShape(window, zone[i]->shape, NULL);
}

void check_zones(button_s **zone, sfRenderWindow *window)
{
    sfVector2i hello = sfMouse_getPositionRenderWindow(window);
    sfVector2f goodbye;

    goodbye.x = hello.x;
    goodbye.y = hello.y;
    for (int i = 0; i <= 9; i++)
        if (zone[i]->shape != NULL)
            see_zones(zone[i], goodbye);
}

void see_zones(button_s *zone, sfVector2f mouse)
{
    sfFloatRect hello = sfRectangleShape_getGlobalBounds(zone->shape);
    const sfFloatRect *bibou = &hello;

    if (sfFloatRect_contains(bibou, mouse.x, mouse.y))
        sfRectangleShape_setFillColor(zone->shape, sfRed);
    else
        sfRectangleShape_setFillColor(zone->shape, sfWhite);
}