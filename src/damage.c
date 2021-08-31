/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** damage
*/

#include "defender.h"

void tower_cannon(object **t_enemy, t *clock,
                int i, button_s *health)
{
    if (health->reset != 5) {
        health->reset = 5;
        health->size.x -= 50;
    }
    return;
}

void tower_shooter(object **t_enemy, t *clock,
                int i, button_s *health)
{
    health->size.x -= 0.05;
    t_enemy[4]->position.y -= 0.2;
    return;
}

void tower_archer(object **t_enemy, t *clock,
                int i, button_s *health)
{
    health->size.x -= 0.2;
    return;
}

void tower_ice(object **t_enemy, t *clock,
                int i, button_s *health)
{
    t_enemy[4]->position.y -= 0.5;
    return;
}

void chose_tower(object **t_enemy,  t *clock,
                    int i, button_s *health)
{
    if (t_enemy[i]->a == 1)
        tower_archer(t_enemy, clock, i, health);
    if (t_enemy[i]->a == 2)
        tower_cannon(t_enemy, clock, i, health);
    if (t_enemy[i]->a == 3)
        tower_ice(t_enemy, clock, i, health);
    if (t_enemy[i]->a == 4)
        tower_shooter(t_enemy, clock, i, health);
    return;
}