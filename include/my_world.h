/*
** EPITECH PROJECT, 2025
** my_world.h
** File description:
** The header file for project my_radar
*/

#ifndef MY_WORLD_
    #define MY_WORLD_
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics/RenderStates.h>
    #include <SFML/Graphics/BlendMode.h>
    #include <stdlib.h>
    #include <math.h>
    #include <limits.h>
    #include "my_world_struct.h"

    #define MIN(x, y) (((x) < (y)) ? (x) : (y))
    #define ABS(x) (((x) < 0) ? (-x) : (x))
    #define MY_PI 3.14159265358979323846
    #define RAD2DEG(x) MY_PI / x * 2.0
    #define DEG2RAD(x) x / MY_PI / 2.0
    #define DRAW_SPRITE(w, s) sfRenderWindow_drawSprite(w, s, NULL)
    #define DRAW_CIRCLE(w, c) sfRenderWindow_drawCircleShape(w, c, NULL)
    #define DRAW_RECT(w, hb) sfRenderWindow_drawRectangleShape(w, hb, NULL)
    #define NB_BTN_TOP 3
    #define NB_BTN_BOT 2
    #define IDLE_BUTTON_TEXTURE "./images/btn_textures/idle_button.png"
    #define HOVER_BUTTON_TEXTURE "./images/btn_textures/hover_button.png"
    #define CLICKED_BUTTON_TEXTURE "./images/btn_textures/clicked_button.png"
    #define INCREASE_HEIGHT_TEXTURE "./images/btn_textures/increase_height.png"
    #define REDUCE_HEIGHT_TEXTURE "./images/btn_textures/reduce_height.png"
    #define RESET_HEIGHT_TEXTURE "./images/btn_textures/reset_height.png"
    #define PLUS_TEXTURE "./images/btn_textures/plus.png"
    #define MINUS_TEXTURE "./images/btn_textures/minus.png"
    #define GRASS_TEXTURE "./images/TextureWorld/grass.png"
    #define DIRT_TEXTURE "./images/TextureWorld/dirt.png"
    #define SNOW_TEXTURE "./images/TextureWorld/snow.png"
    #define TEXT_FONT "./font/font.ttf"

int help(void);
void my_putstr(char const *str);
game_t *init_game(void);
void init_background(game_t *game);
void game_loop(game_t *game);
void draw_map(game_t *game);
void free_ressources(game_t *game);
sfVector2f **create_2d_map(game_t *game, int **map3d);
void destroy_2d_map(sfVector2u *size, sfVector2f **map2d);
void manage_mouse_click(sfMouseButtonEvent *mouse, game_t *game);
void change_map_size(game_t *game, sfVector2u *new_size);
void check_if_button_are_hooverd(game_t *game);
int check_coll(buttons_t *btn, sfVector2i *p_a, sfVector2f *p_b);
void reset_button_states(buttons_t **buttons, int i);
void init_top_buttons(buttons_t **btn_array);
void init_bot_buttons(game_t *game);
#endif
