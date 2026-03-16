/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** init_game.c
*/
#include "my_world.h"
#include <stdio.h>

static sfRenderWindow *create_window(int x, int y, int bpp, char *name)
{
    sfVideoMode video_mode = {x, y, bpp};
    sfRenderWindow *window = sfRenderWindow_create(video_mode, name,
        sfClose | sfResize, NULL);

    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

static void init_view(game_t *game)
{
    view_t *view = malloc(sizeof(view_t));
    sfVector2u coords = {.x = 960, .y = 140};
    sfVector2u angle = {.x = 0, .y = 3};

    view->zoom = 100;
    view->coords = coords;
    view->angle = angle;
    game->view = view;
}

static void init_map(game_t *game)
{
    sfVector2u size = {.x = 10, .y = 10};

    game->mapsize = size;
    game->map3d = malloc(size.x * sizeof(int *));
    for (unsigned int i = 0; i < size.x; ++i) {
        game->map3d[i] = malloc(size.y * sizeof(int));
        for (unsigned int j = 0; j < size.y; ++j) {
            game->map3d[i][j] = 0;
        }
    }
}

static void init_infobox(infobox_t **info_array)
{
    int i = 0;
    int posx = 20;
    infobox_t *info = NULL;

    while (i < NB_BTN_BOT + NB_BTN_TOP) {
        info = malloc(sizeof(infobox_t));
        info->help_text = sfText_create();
        info->font = sfFont_createFromFile(TEXT_FONT);
        sfText_setFont(info->help_text, info->font);
        sfText_setString(info->help_text, "Lorem Ipsum");
        sfText_setPosition(info->help_text, (sfVector2f){.x = posx, .y = 100});
        info_array[i] = info;
        posx = posx + 200;
        i++;
    }
    sfText_setPosition(info_array[3]->help_text, (sfVector2f){20, 1000});
    sfText_setPosition(info_array[4]->help_text, (sfVector2f){120, 1000});
}

static void init_game_texture(game_t *game)
{
    game->game_textures = malloc(sizeof(world_textures_t));
    game->game_textures->grass = sfTexture_createFromFile(GRASS_TEXTURE, NULL);
    game->game_textures->dirt = sfTexture_createFromFile(DIRT_TEXTURE, NULL);
    game->game_textures->snow = sfTexture_createFromFile(SNOW_TEXTURE, NULL);
}

static void init_mode(game_t *game)
{
    build_mode_t *mode = malloc(sizeof(build_mode_t));

    mode->down = 0;
    mode->up = 0;
    mode->reset = 0;
    game->mode = mode;
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->window = create_window(1920, 1080, 32, "My World");
    game->clock = sfClock_create();
    init_background(game);
    game->music = sfMusic_createFromFile("sound/background_music.mp3");
    init_view(game);
    init_map(game);
    init_mode(game);
    game->top_buttons = malloc(sizeof(buttons_t *) * NB_BTN_TOP);
    game->infobox = malloc(sizeof(infobox_t *) * (NB_BTN_TOP + NB_BTN_BOT));
    init_game_texture(game);
    init_top_buttons(game->top_buttons);
    init_bot_buttons(game);
    init_infobox(game->infobox);
    return game;
}
