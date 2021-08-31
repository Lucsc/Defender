/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** damageother
*/

#include "defender.h"

void tower_cannonbis(t *clock, object **t_enemy,
                int i, button_s *health)
{
    if (health->reset != 5) {
        health->reset = 5;
        health->size.x -= 25;
    }
    return;
}

void tower_shooterbis(t *clock, object **t_enemy,
                int i, button_s *health)
{
    health->size.x -= 0.02;
    if (t_enemy[5]->position.x < 325)
        t_enemy[5]->position.x -= 0.1;
    if (t_enemy[5]->position.x >= 325 && t_enemy[5]->position.y >= 260
        && t_enemy[5]->position.x < 770)
        t_enemy[5]->position.y += 0.1;
    if (t_enemy[5]->position.y < 260 && t_enemy[5]->position.x <= 770
            && t_enemy[5]->position.x >= 325)
        t_enemy[5]->position.x -= 0.1;
    if (t_enemy[5]->position.x > 770 && t_enemy[5]->position.y < 750)
        t_enemy[5]->position.y -= 0.1;
    if (t_enemy[5]->position.y >= 750 && t_enemy[5]->position.x >= 770)
        t_enemy[5]->position.x -= 0.1;
    return;
}

void tower_archerbis(t *clock, object **t_enemy,
                int i, button_s *health)
{
    health->size.x -= 0.05;
    return;
}

void tower_icebis(t *clock, object **t_enemy,
                int i, button_s *health)
{
    if (t_enemy[5]->position.x < 325)
        t_enemy[5]->position.x -= 0.2;
    if (t_enemy[5]->position.x >= 325 && t_enemy[5]->position.y >= 260
        && t_enemy[5]->position.x < 770)
        t_enemy[5]->position.y += 0.2;
    if (t_enemy[5]->position.y < 260 && t_enemy[5]->position.x <= 770
            && t_enemy[5]->position.x >= 325)
        t_enemy[5]->position.x -= 0.2;
    if (t_enemy[5]->position.x > 770 && t_enemy[5]->position.y < 750)
        t_enemy[5]->position.y -= 0.2;
    if (t_enemy[5]->position.y >= 750 && t_enemy[5]->position.x >= 770)
        t_enemy[5]->position.x -= 0.2;
    return;
}

void chose_towerbis(t *clock, object **t_enemy,
                    int i, button_s *health)
{
    if (t_enemy[i]->a == 1)
        tower_archerbis(clock, t_enemy, i, health);
    if (t_enemy[i]->a == 2)
        tower_cannonbis(clock, t_enemy, i, health);
    if (t_enemy[i]->a == 3)
        tower_icebis(clock, t_enemy, i, health);
    if (t_enemy[i]->a == 4)
        tower_shooterbis(clock, t_enemy, i, health);
    return;
}