/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** cursor
*/

#include "defender.h"

sfSprite *cursor(sfRenderWindow *window, char *filepath, int x, int y)
{
    sfSprite *cursor = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfVector2f position;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    position.x = mouse.x;
    position.x -= x;
    position.y = mouse.y;
    position.y -= y;
    sfSprite_setTexture(cursor, texture, sfTrue);
    sfSprite_setPosition(cursor, position);
    return (cursor);
}

void changecursor(sfRenderWindow *w, object **game)
{
    sfRenderWindow_setMouseCursorVisible(w, sfFalse);
    if (game[0]->i == 0)
        sfRenderWindow_setMouseCursorVisible(w, sfTrue);
    if (game[0]->i == 1)
        sfRenderWindow_drawSprite(w, cursor(w, "media/archer.png", 115, 240),
                                    NULL);
    if (game[0]->i == 2)
        sfRenderWindow_drawSprite(w, cursor(w, "media/cannon.png", 110, 220),
                                    NULL);
    if (game[0]->i == 3)
        sfRenderWindow_drawSprite(w, cursor(w, "media/ice.png", 90, 240),
                                    NULL);
    if (game[0]->i == 4)
        sfRenderWindow_drawSprite(w, cursor(w, "media/shooters.png", 95, 250),
                                    NULL);
}

void printtower(sfRenderWindow *window, object **game, button_s *zone)
{
    int i = 0;

    for (; game[i] != NULL; i++);
    if (game[0]->i == 1) {
        zone->position.x -= 82;
        zone->position.y -= 200;
        game[i] = create_sprite("media/archer.png", zone->position,
                                (sfIntRect){0, 0, 0, 0});
        game[i] = all_circles(game[i], game[0]->a);
        game[i]->a = game[0]->i;
    }
    if (game[0]->i == 2) {
        zone->position.x -= 60;
        zone->position.y -= 160;
        game[i] = create_sprite("media/cannon.png", zone->position,
                                (sfIntRect){0, 0, 0, 0});
        game[i] = all_circles(game[i], game[0]->a);
        game[i]->a = game[0]->i;
    }
    printtowerbis(window, game, zone, i);
}

int seezonesontower(button_s *zone, sfVector2f mouse)
{
    sfFloatRect hello;
    const sfFloatRect *bibou = &hello;

    if (zone == NULL)
        return (0);
    hello = sfRectangleShape_getGlobalBounds(zone->shape);
    if (sfFloatRect_contains(bibou, mouse.x, mouse.y))
        return (2);
    return (0);
}

void checkzonesontower(button_s **zone, sfRenderWindow *window, object **game)
{
    sfVector2i hello = sfMouse_getPositionRenderWindow(window);
    sfVector2f goodbye;
    goodbye.x = hello.x;
    goodbye.y = hello.y;
    game[0]->a = 0;
    int r = 0;

    for (; game[0]->a <= 9; game[0]->a++) {
        if (zone[game[0]->a]->shape != NULL)
            r = seezonesontower(zone[game[0]->a], goodbye);
        if (r == 2)
            break;
    }
}