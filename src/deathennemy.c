/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** deathennemy
*/

#include "defender.h"

void ennemylife(sfRenderWindow *window, t **clock,
                    object **game, button_s **life)
{
    clock[0]->time = sfClock_getElapsedTime(clock[0]->clock);
    clock[0]->seconds = clock[0]->time.microseconds / 1000000.0;
    sfSprite_setTextureRect(game[4]->sprite, game[4]->rect);
    sfSprite_setTextureRect(game[5]->sprite, game[5]->rect);
    if (clock[0]->seconds > 0.001) {
        skl_bar(window, game, life, clock[1]);
        sfClock_restart(clock[0]->clock);
    }
}

void check_death(t *clock, object **t_enemy,
                    int i, button_s **health)
{
    sfFloatRect hello = sfCircleShape_getGlobalBounds(t_enemy[i]->
                        circles->shape);
    const sfFloatRect *bibou = &hello;

    if (sfFloatRect_contains(bibou, t_enemy[4]->position.x,
                                t_enemy[4]->position.y)) {
        chose_tower(t_enemy, clock, i, health[3]);
    }
    if (sfFloatRect_contains(bibou, t_enemy[5]->position.x,
                                t_enemy[5]->position.y))
        chose_towerbis(clock, t_enemy, i, health[1]);
}

circle_t *cre_circ(sfVector2f pos, float radius)
{
    circle_t *butt = malloc(sizeof(button_s));

    if (butt == NULL)
        return NULL;
    butt->shape = sfCircleShape_create();
    butt->position = pos;
    butt->radius = radius;
    sfCircleShape_setRadius(butt->shape, butt->radius);
    sfCircleShape_setPosition(butt->shape, butt->position);
    sfCircleShape_setFillColor(butt->shape, sfBlack);
    return butt;
}

object *all_circles(object *zone, int i)
{
    switch (i) {
        case 0 : zone->circles = cre_circ((sfVector2f){210, 400}, 180); break;
        case 1 : zone->circles = cre_circ((sfVector2f){210, 680}, 150); break;
        case 2 : zone->circles = cre_circ((sfVector2f){370, 600}, 300); break;
        case 3 : zone->circles = cre_circ((sfVector2f){330, 260}, 250); break;
        case 4 : zone->circles = cre_circ((sfVector2f){300, 200}, 200); break;
        case 5 : zone->circles = cre_circ((sfVector2f){600, 200}, 200); break;
        case 6 : zone->circles = cre_circ((sfVector2f){650, 300}, 250); break;
        case 7 : zone->circles = cre_circ((sfVector2f){710, 620}, 200); break;
        case 8 : zone->circles = cre_circ((sfVector2f){1190, 350}, 200); break;
        case 9 : zone->circles = cre_circ((sfVector2f){1210, 150}, 180); break;
    }
    return (zone);
}