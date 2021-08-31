/*
** EPITECH PROJECT, 2021
** bsdefender
** File description:
** main
*/

#include "defender.h"

int main(int ac, char **av, char **env)
{
    if (!*env)
        return 84;
    sfVideoMode video_mode = {1918, 1080, 32};
    sfRenderWindow *window =
    sfRenderWindow_create(video_mode, "My_window", sfResize | sfClose, NULL);
    music *song = create_music("media/theme.ogg");

    sfRenderWindow_setFramerateLimit(window, 60);
    if (ac != 1)
        return 84;
    start_screen(window);
    sfMusic_destroy(song->music);
    sfRenderWindow_destroy(window);
    return (0);
}