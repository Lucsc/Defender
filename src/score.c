/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** gold
*/

#include "defender.h"

sfText *scores(sfRenderWindow *window, char *buffer)
{
    sfVector2f position = {1650, 60};
    sfFont *font = sfFont_createFromFile("media/score.ttf");
    sfText *text2 = sfText_create();

    sfText_setFont(text2, font);
    sfText_setString(text2, buffer);
    sfText_setCharacterSize(text2, 100);
    sfText_setFillColor(text2, sfWhite);
    sfText_setStyle(text2, sfTextBold);
    sfText_setPosition(text2, position);
    return (text2);
}

void converttochar(sfRenderWindow *window, int i, char *score, int r)
{
    if (i > 0) {
        score[r] = i % 10 + '0';
        i = i / 10;
        r--;
        converttochar(window, i, score, r);
    }
    sfRenderWindow_drawText(window, scores(window, score), NULL);
}

void create_score(sfRenderWindow *window, int i, int j)
{
    char score[] = "00000";
    char gold[] = "00000";

    converttogold(window, j, gold, 4);
    converttochar(window, i, score, 4);
}

void changelife(sfRenderWindow *window, object **game,
                    button_s **life, t *clock)
{
    if (life[1]->size.x <= 0) {
        game[5]->b++;
        game[3]->b += 42;
        life[1]->reset = 0;
        life[1]->size.x = 100;
        game[5]->position.x = 0;
        game[5]->position.y = 750;
    }
    if (life[3]->size.x <= 0) {
        game[5]->b++;
        game[3]->b += 42;
        life[3]->reset = 0;
        life[3]->size.x = 200;
        game[4]->position.y = 0;
    }
    return;
}