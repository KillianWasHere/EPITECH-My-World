/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** init_background.c
*/
#include "my_world.h"

void init_background(game_t *game)
{
    game->bg = malloc(sizeof(background_t));
    game->bg->bg_texture = sfTexture_createFromFile("images/the_world.png",
        NULL);
    game->bg->bg_sprite = sfSprite_create();
    sfSprite_setTexture(game->bg->bg_sprite, game->bg->bg_texture, sfFalse);
    sfSprite_setScale(game->bg->bg_sprite, (sfVector2f){1.5, 1.5});
}
