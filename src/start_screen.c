/*
** EPITECH PROJECT, 2021
** bsdefender
** File description:
** start_screen
*/

#include "defender.h"

void analyse_eventsgame(sfRenderWindow *window, object **game,
                        button_s **tow, button_s **zone)
{
    sfMouseButtonEvent click;
    sfVector2i hello = sfMouse_getPositionRenderWindow(window);
    sfVector2f goodbye;
    goodbye.x = hello.x;
    goodbye.y = hello.y;

    if (game[0]->event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (game[0]->event.type == sfEvtMouseButtonPressed && game[0]->i != 0) {
        checkzonesontower(zone, window, game);
        if (game[0]->a != 10) {
            printtower(window, game, zone[game[0]->a]);
            zone[game[0]->a]->shape = NULL;
        }
        game[0]->i = 0;
    }
    eventsgame(window, game, tow, zone);
}

int gamescreen(sfRenderWindow *window)
{
    object **game = tabobject(game);
    button_s **tower = gamebutton(tower);
    button_s **zone = all_zone(zone);
    t **clock = createtabclock(clock);
    button_s **life = mob_health(life, game);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &game[0]->event)) {
            analyse_eventsgame(window, game, tower, zone);
            go_pause(window, game, life, zone);
        }
        drawgamemap(game, window, clock, zone);
        drawzones(zone, window);
        drawscreen(tower, window);
        check_zones(zone, window);
        ennemylife(window, clock, game, life);
        sfRenderWindow_display(window);
    }
    for (int i = 0; game[i] != NULL; i++)
        free(game[i]);
}

int start_screen(sfRenderWindow *window)
{
    object **bgmain = objectstart(bgmain);
    button_s **info = buttonstart(info);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &bgmain[0]->event)) {
            analyse_events(window, bgmain[0]->event, info[0], info[2]);
            gohelp(window, bgmain[0]->event, info[1]);
        }
        drawstartscreen(info, bgmain, window);
    }
    for (int i = 0; i <= 2; i++)
        free(info[i]);
    for (int i = 0; i <= 1; i++)
        free(bgmain[i]);
    free(info);
    free(bgmain);
}

void analyse_events(sfRenderWindow *window, sfEvent event,
                    button_s *button, button_s *quit)
{
    sfMouseButtonEvent click;
    sfVector2i hello = sfMouse_getPositionRenderWindow(window);
    sfVector2f goodbye;

    goodbye.x = hello.x;
    goodbye.y = hello.y;
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed) {
        button_is_clicked(button, goodbye, window);
        button_leave(quit, goodbye, window);
    }
}