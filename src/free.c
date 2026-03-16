/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** free.c
*/
#include "my_world.h"

static void free_textures(game_t *game)
{
    sfTexture_destroy(game->game_textures->grass);
    sfTexture_destroy(game->game_textures->dirt);
    sfTexture_destroy(game->game_textures->snow);
}

static void free_map(game_t *game)
{
    for (unsigned int i = 0; i < game->mapsize.x; ++i) {
        free(game->map3d[i]);
    }
    free(game->map3d);
}

static void free_text(game_t *game)
{
    for (int i = 0; i < NB_BTN_TOP + NB_BTN_BOT; i++) {
        sfText_destroy(game->infobox[i]->help_text);
        sfFont_destroy(game->infobox[i]->font);
        free(game->infobox[i]);
    }
    free(game->infobox);
}

static void free_buttons(game_t *game)
{
    for (unsigned int i = 0; i < NB_BTN_TOP; i++) {
        sfTexture_destroy(game->top_buttons[i]->click);
        sfTexture_destroy(game->top_buttons[i]->hoover);
        sfTexture_destroy(game->top_buttons[i]->normal);
        sfTexture_destroy(game->top_buttons[i]->image);
        sfSprite_destroy(game->top_buttons[i]->btn_sprite);
        sfSprite_destroy(game->top_buttons[i]->btn_image);
        free(game->top_buttons[i]);
    }
    free(game->top_buttons);
    for (unsigned int i = 0; i < NB_BTN_BOT; i++) {
        sfTexture_destroy(game->bottom_buttons[i]->click);
        sfTexture_destroy(game->bottom_buttons[i]->hoover);
        sfTexture_destroy(game->bottom_buttons[i]->normal);
        sfTexture_destroy(game->bottom_buttons[i]->image);
        sfSprite_destroy(game->bottom_buttons[i]->btn_sprite);
        sfSprite_destroy(game->bottom_buttons[i]->btn_image);
        free(game->bottom_buttons[i]);
    }
    free(game->bottom_buttons);
}

static void free_bg(game_t *game)
{
    sfSprite_destroy(game->bg->bg_sprite);
    sfTexture_destroy(game->bg->bg_texture);
    free(game->bg);
}

void free_ressources(game_t *game)
{
    sfClock_destroy(game->clock);
    free_bg(game);
    sfMusic_destroy(game->music);
    free_buttons(game);
    free_text(game);
    free_map(game);
    free_textures(game);
    free(game->game_textures);
    free(game->mode);
    free(game->view);
    sfRenderWindow_destroy(game->window);
    free(game);
}
