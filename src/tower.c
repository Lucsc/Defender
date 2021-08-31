/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** tower
*/

#include "defender.h"

int towertopleft(button_s *button, sfVector2f click, sfRenderWindow *w, int i)
{
    sfFloatRect hello = sfRectangleShape_getGlobalBounds(button->shape);
    const sfFloatRect *bibou = &hello;
    music *thanks;

    if (sfFloatRect_contains(bibou, click.x, click.y)) {
        i = 1;
        thanks = create_sound("media/merci.ogg");
        return (i);
    } else
        return i;
}

int towertopright(button_s *button, sfVector2f click, sfRenderWindow *w, int i)
{
    sfFloatRect hello = sfRectangleShape_getGlobalBounds(button->shape);
    const sfFloatRect *bibou = &hello;
    music *thanks;

    if (sfFloatRect_contains(bibou, click.x, click.y)) {
        i = 2;
        thanks = create_sound("media/merci.ogg");
        return (i);
    } else
        return i;
}

int towerdownleft(button_s *button, sfVector2f click, sfRenderWindow *w, int i)
{
    sfFloatRect hello = sfRectangleShape_getGlobalBounds(button->shape);
    const sfFloatRect *bibou = &hello;
    music *thanks;

    if (sfFloatRect_contains(bibou, click.x, click.y)) {
        i = 3;
        thanks = create_sound("media/merci.ogg");
        return (i);
    } else
        return i;
}

int towerdownright(button_s *button, sfVector2f clic, sfRenderWindow *w, int i)
{
    sfFloatRect hello = sfRectangleShape_getGlobalBounds(button->shape);
    const sfFloatRect *bibou = &hello;
    music *thanks;

    if (sfFloatRect_contains(bibou, clic.x, clic.y)) {
        i = 4;
        thanks = create_sound("media/merci.ogg");
        return (i);
    } else
        return i;
}

void printtowerbis(sfRenderWindow *window, object **game, button_s *zon, int i)
{
    if (game[0]->i == 3) {
        zon->position.x -= 50;
        zon->position.y -= 200;
        game[i] = create_sprite("media/ice.png", zon->position,
                                (sfIntRect){0, 0, 0, 0});
        game[i] = all_circles(game[i], game[0]->a);
        game[i]->a = game[0]->i;
    }
    if (game[0]->i == 4) {
        zon->position.x -= 50;
        zon->position.y -= 200;
        game[i] = create_sprite("media/shooters.png", zon->position,
                                (sfIntRect){0, 0, 0, 0});
        game[i] = all_circles(game[i], game[0]->a);
        game[i]->a = game[0]->i;
    }
}