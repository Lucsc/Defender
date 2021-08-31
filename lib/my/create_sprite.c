/*
** EPITECH PROJECT, 2021
** bsdefender
** File description:
** create_sprite
*/

#include "my.h"

struct object *create_sprite(const char *pathfile,
                            sfVector2f vector, sfIntRect rect)
{
    object *spritecreate = malloc(sizeof(object));
    if (spritecreate == NULL)
        return (NULL);
    spritecreate->sprite = sfSprite_create();
    spritecreate->texture = sfTexture_createFromFile(pathfile, NULL);
    sfSprite_setTexture(spritecreate->sprite, spritecreate->texture, sfTrue);
    spritecreate->position = vector;
    sfSprite_setPosition(spritecreate->sprite, vector);
    spritecreate->rect = rect;
    return spritecreate;
}