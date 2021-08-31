/*
** EPITECH PROJECT, 2021
** bsdefender
** File description:
** create_music
*/

#include "my.h"

struct music *create_music(const char *filepath)
{
    music *sound = malloc(sizeof(music));

    sound->music = sfMusic_createFromFile(filepath);
    sfMusic_setLoop(sound->music, sfTrue);
    sfMusic_play(sound->music);
    sfMusic_setVolume(sound->music, 35);
    return sound;
}

struct music *create_sound(const char *filepath)
{
    music *sound = malloc(sizeof(music));

    sound->music = sfMusic_createFromFile(filepath);
    sfMusic_setLoop(sound->music, sfFalse);
    sfMusic_play(sound->music);
    sfMusic_setVolume(sound->music, 50);
    return sound;
}