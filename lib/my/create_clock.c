/*
** EPITECH PROJECT, 2021
** bsdefender
** File description:
** create_clock
*/

#include "my.h"

struct t *create_clock(void)
{
    t *time = malloc (sizeof(t));

    time->clock = sfClock_create();
    return time;
}