/*
** EPITECH PROJECT, 2021
** bsdefender
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct object {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f position;
    sfEvent event;
    int i;
    int a;
    int b;
} object;

typedef struct music {
    sfMusic *music;
} music;

typedef struct t {
    sfClock* clock;
    sfTime time;
    float seconds;
} t;

void move_rect(sfIntRect *rect, int offset, int max_value);
int my_putstr(char const *str);
void my_putchar(char c);
struct t *create_clock(void);
struct music *create_music(const char *filepath);
struct object *create_sprite(const char *pathfile,
                            sfVector2f vector, sfIntRect rect);
struct music *create_sound(const char *filepath);

#endif /* !MY_H_ */