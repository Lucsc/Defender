/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** gold
*/

#include "defender.h"

sfText *gold(sfRenderWindow *window, char *buffer)
{
    sfVector2f position = {1650, 910};
    sfFont *font = sfFont_createFromFile("media/score.ttf");
    sfText *text2 = sfText_create();

    sfText_setFont(text2, font);
    sfText_setString(text2, buffer);
    sfText_setCharacterSize(text2, 100);
    sfText_setFillColor(text2, sfYellow);
    sfText_setStyle(text2, sfTextBold);
    sfText_setPosition(text2, position);
    return (text2);
}

void converttogold(sfRenderWindow *window, int i, char *score, int r)
{
    if (i > 0) {
        score[r] = i % 10 + '0';
        i = i / 10;
        r--;
        converttogold(window, i, score, r);
    }
    sfRenderWindow_drawText(window, gold(window, score), NULL);
}