/*
** EPITECH PROJECT, 2021
** bsdefender
** File description:
** button
*/

#include "defender.h"

int button_home(button_s *button, sfVector2f click, sfRenderWindow *w)
{
    sfFloatRect hello = sfRectangleShape_getGlobalBounds(button->shape);
    const sfFloatRect *bibou = &hello;

    if (sfFloatRect_contains(bibou, click.x, click.y))
        start_screen(w);
    else
        return 0;
}

int button_resume(button_s *button, sfVector2f click, sfRenderWindow *w)
{
    sfFloatRect hello = sfRectangleShape_getGlobalBounds(button->shape);
    const sfFloatRect *bibou = &hello;

    if (sfFloatRect_contains(bibou, click.x, click.y))
        return (2);
    else
        return 0;
}

int button_help(button_s *button , sfVector2f click, sfRenderWindow *w)
{
    sfFloatRect hello = sfRectangleShape_getGlobalBounds(button->shape);
    const sfFloatRect *bibou = &hello;

    if (sfFloatRect_contains(bibou, click.x, click.y))
        helpwindow();
    else
        return 0;
}

int button_leave(button_s *button, sfVector2f click, sfRenderWindow *w)
{
    sfFloatRect hello = sfRectangleShape_getGlobalBounds(button->shape);
    const sfFloatRect *bibou = &hello;

    if (sfFloatRect_contains(bibou, click.x, click.y)) {
        sfRenderWindow_close(w);
    }
    else
        return 0;
}

int button_is_clicked(button_s *button, sfVector2f click, sfRenderWindow *w)
{
    sfFloatRect hello = sfRectangleShape_getGlobalBounds(button->shape);
    const sfFloatRect *bibou = &hello;

    if (sfFloatRect_contains(bibou, click.x, click.y)) {
        gamescreen(w);
    }
    else
        return 0;
}