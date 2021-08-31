/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-brice.boualavong
** File description:
** gameplay
*/

#include "defender.h"

t **createtabclock(t **clock)
{
    clock = malloc(sizeof(t *) * 2);
    clock[0] = create_clock();
    clock[1] = create_clock();
    return (clock);
}

void healthbar(sfRenderWindow *window, object **game, button_s **bar)
{
    music *damage;

    if (game[5]->position.x >= 1200) {
        damage = create_sound("media/oof.ogg");
        bar[10]->size.x -= 100;
    }
    if (game[4]->position.y == 650) {
        damage = create_sound("media/oof.ogg");
        bar[10]->size.x -= 50;
    }
    if (bar[10]->size.x <= 0)
        lostscreen(window, damage);
    sfRectangleShape_setSize(bar[10]->shape, bar[10]->size);
    sfRectangleShape_setFillColor(bar[10]->shape, sfGreen);
    sfRenderWindow_drawRectangleShape(window, bar[10]->shape, NULL);
}

button_s **mob_health(button_s **health, object **game)
{
    health = malloc(sizeof(button_s **) * 4);
    health[0] = init_butt(game[5]->position, (sfVector2f){100, 20});
    health[1] = init_butt(game[5]->position, (sfVector2f){100, 20});
    health[2] = init_butt(game[4]->position, (sfVector2f){100, 20});
    health[3] = init_butt(game[4]->position, (sfVector2f){100, 20});
    return health;
}

void drawbar(sfRenderWindow *window, object **game, button_s **life)
{
    sfRectangleShape_setPosition(life[0]->shape, game[5]->position);
    sfRectangleShape_setPosition(life[1]->shape, game[5]->position);
    sfRectangleShape_setPosition(life[2]->shape, game[4]->position);
    sfRectangleShape_setPosition(life[3]->shape, game[4]->position);
    sfRectangleShape_setSize(life[1]->shape, life[1]->size);
    sfRectangleShape_setSize(life[3]->shape, life[3]->size);
    sfRectangleShape_setFillColor(life[0]->shape, sfRed);
    sfRectangleShape_setFillColor(life[1]->shape, sfGreen);
    sfRectangleShape_setFillColor(life[2]->shape, sfRed);
    sfRectangleShape_setFillColor(life[3]->shape, sfGreen);
    sfRenderWindow_drawRectangleShape(window, life[0]->shape, NULL);
    sfRenderWindow_drawRectangleShape(window, life[1]->shape, NULL);
    sfRenderWindow_drawRectangleShape(window, life[2]->shape, NULL);
    sfRenderWindow_drawRectangleShape(window, life[3]->shape, NULL);
}

void skl_bar(sfRenderWindow *window, object **game, button_s **life, t *clock)
{
    for (int i = 6; game[i] != NULL; i++)
        check_death(clock, game, i, life);
    if (life[1]->size.x > life[0]->size.x)
        life[1]->size.x = life[0]->size.x;
    if (life[3]->size.x > life[2]->size.x)
        life[3]->size.x = life[2]->size.x;
    changelife(window, game, life, clock);
    drawbar(window, game, life);
}