/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** enemy
*/

#include "defender.h"

void drawgamemap(object **game, sfRenderWindow *window,
                    t **clock, button_s **zone)
{
    sfRenderWindow_clear(window, sfTransparent);
    moveenemys(game, clock[1], window, zone);
    moving_sprite(clock[0], game[2], game[3]);
    sfSprite_setTextureRect(game[2]->sprite, game[2]->rect);
    sfSprite_setTextureRect(game[3]->sprite, game[3]->rect);
    sfRenderWindow_drawSprite(window, game[0]->sprite, NULL);
    for (int i = 6; game[i] != NULL; i++)
        sfRenderWindow_drawSprite(window, game[i]->sprite, NULL);
    sfRenderWindow_drawSprite(window, game[4]->sprite, NULL);
    sfRenderWindow_drawSprite(window, game[5]->sprite, NULL);
    sfRenderWindow_drawSprite(window, game[1]->sprite, NULL);
    sfRenderWindow_drawSprite(window, game[2]->sprite, NULL);
    sfRenderWindow_drawSprite(window, game[3]->sprite, NULL);
    sfRenderWindow_drawRectangleShape(window, zone[10]->shape, NULL);
    create_score(window, game[5]->b, game[3]->b);
    changecursor(window, game);
}

object **tabobject(object **game)
{
    game = malloc(sizeof(object **)* 17);
    game[0] = create_sprite("media/gmscr.png", (sfVector2f){0, 0},
                                (sfIntRect){0, 0, 0, 0});
    game[0]->i = 0;
    game[1] = create_sprite("media/castle.png", (sfVector2f){1260, 620},
                                (sfIntRect){0, 0, 0, 0});
    game[2] = create_sprite("media/bck.png", (sfVector2f){1265, -50},
                                (sfIntRect){0, 0, 240, 202});
    game[3] = create_sprite("media/bck.png", (sfVector2f){-65, 715},
                                (sfIntRect){0, 0, 240, 202});
    game[4] = create_sprite("media/enemy.png", (sfVector2f){1320, 0},
                                        (sfIntRect){0, 225, 110, 115});
    game[5] = create_sprite("media/enemy.png", (sfVector2f){0, 750},
                                    (sfIntRect){0, 112, 110, 115});
    game[3]->b = 126;
    game[5]->b = 0;
    for (int i = 6; i <= 16; i++)
        game[i] = NULL;
    return (game);
}

object *changepossecond(object *enemy, int x)
{
    if (enemy->position.y >= 650)
        enemy->position.y = 0;
    enemy->position.y += x;
    sfSprite_setPosition(enemy->sprite, enemy->position);
    return (enemy);
}

object *changeposfirst(object *enemy, int x)
{
    if (enemy->position.x < 325)
        enemy->position.x += x;
    if (enemy->position.x >= 325 && enemy->position.y >= 260
        && enemy->position.x < 770)
        enemy->position.y -= x;
    if (enemy->position.y < 260 && enemy->position.x <= 770
            && enemy->position.x >= 325)
        enemy->position.x += x;
    if (enemy->position.x > 770 && enemy->position.y < 750)
        enemy->position.y += x;
    if (enemy->position.y >= 750 && enemy->position.x >= 770)
        enemy->position.x += x;
    if (enemy->position.x >= 1201)
        enemy->position.x = 0;
    sfSprite_setPosition(enemy->sprite, enemy->position);
    return (enemy);
}

t *moveenemys(object **game, t *clock, sfRenderWindow *window, button_s **zone)
{
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->seconds = clock->time.microseconds / 1000000.0;
    sfSprite_setTextureRect(game[4]->sprite, game[4]->rect);
    sfSprite_setTextureRect(game[5]->sprite, game[5]->rect);
    if (clock->seconds > 0.1) {
        game[5] = changeposfirst(game[5], 5);
        game[4] = changepossecond(game[4], 5);
        healthbar(window, game, zone);
        sfClock_restart(clock->clock);
    }
    if (clock->seconds > 0.1) {
        move_rect(&game[4]->rect, 110, 550);
        move_rect(&game[5]->rect, 110, 550);
        sfClock_restart(clock->clock);
    }
    return (clock);
}