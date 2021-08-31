/*
** EPITECH PROJECT, 2021
** bsdefender
** File description:
** move_rect
*/

#include "my.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;

    if (rect->left >= max_value)
        rect->left = 0;
}