/*
** EPITECH PROJECT, 2025
** my_radar_struct.h
** File description:
** The header file for the structures of the project my_radar
*/

#ifndef MY_WORLD_STRUCT_
    #define MY_WORLD_STRUCT_
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>

typedef struct buttons {
    sfTexture *normal;
    sfTexture *hoover;
    sfTexture *click;
    sfTexture *image;
    sfSprite *btn_sprite;
    sfSprite *btn_image;
    int state;
} buttons_t;

typedef struct infobox {
    sfText *help_text;
    sfFont *font;
} infobox_t;

typedef struct view {
    sfVector2u coords;
    sfVector2u angle;
    unsigned int zoom;
} view_t;

typedef struct build_mode {
    unsigned int up;
    unsigned int down;
    unsigned int reset;
} build_mode_t;

typedef struct world_textures {
    sfTexture *grass;
    sfTexture *dirt;
    sfTexture *snow;
} world_textures_t;

typedef struct background {
    sfTexture *bg_texture;
    sfSprite *bg_sprite;
} background_t;

typedef struct game {
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    background_t *bg;
    sfMusic *music;
    int **map3d;
    sfVector2u mapsize;
    view_t *view;
    build_mode_t *mode;
    buttons_t **top_buttons;
    buttons_t **bottom_buttons;
    infobox_t **infobox;
    world_textures_t *game_textures;
} game_t;

#endif
