/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** init_game.c
*/
#include "my_world.h"

static void init_button_images(buttons_t *btn, int i)
{
    btn->btn_image = sfSprite_create();
    if (i == 0)
        btn->image = sfTexture_createFromFile(RESET_HEIGHT_TEXTURE, NULL);
    if (i == 1)
        btn->image = sfTexture_createFromFile(INCREASE_HEIGHT_TEXTURE, NULL);
    if (i == 2)
        btn->image = sfTexture_createFromFile(REDUCE_HEIGHT_TEXTURE, NULL);
    if (i == 3)
        btn->image = sfTexture_createFromFile(MINUS_TEXTURE, NULL);
    if (i == 4)
        btn->image = sfTexture_createFromFile(PLUS_TEXTURE, NULL);
    sfSprite_setTexture(btn->btn_image, btn->image, sfFalse);
}

static void init_buttons_texture(buttons_t *btn)
{
    sfTexture *normal = sfTexture_createFromFile(IDLE_BUTTON_TEXTURE, NULL);
    sfTexture *hoover = sfTexture_createFromFile(HOVER_BUTTON_TEXTURE, NULL);
    sfTexture *click = sfTexture_createFromFile(CLICKED_BUTTON_TEXTURE, NULL);

    btn->normal = normal;
    btn->hoover = hoover;
    btn->click = click;
    sfSprite_setTexture(btn->btn_sprite, normal, sfFalse);
}

void init_top_buttons(buttons_t **btn_array)
{
    int i = 0;
    int posx = 20;
    buttons_t *btn = NULL;

    while (i < NB_BTN_TOP) {
        btn = malloc(sizeof(buttons_t));
        btn->state = 0;
        btn->btn_sprite = sfSprite_create();
        init_buttons_texture(btn);
        init_button_images(btn, i);
        sfSprite_setPosition(btn->btn_sprite, (sfVector2f){.x = posx, .y = 20});
        sfSprite_setScale(btn->btn_sprite, (sfVector2f){.x = 0.3, .y = 0.18});
        sfSprite_setPosition(btn->btn_image,
            (sfVector2f){.x = posx + 55, .y = 25});
        sfSprite_setScale(btn->btn_image, (sfVector2f){.x = 0.5, .y = 0.5});
        btn_array[i] = btn;
        posx = posx + 200;
        i++;
    }
}

void init_bot_buttons(game_t *game)
{
    buttons_t **btn_arr = malloc(sizeof(buttons_t *) * NB_BTN_BOT);

    for (unsigned int i = 0; i < NB_BTN_BOT; ++i) {
        btn_arr[i] = malloc(sizeof(buttons_t));
        btn_arr[i]->state = 0;
        btn_arr[i]->btn_sprite = sfSprite_create();
        init_buttons_texture(btn_arr[i]);
        init_button_images(btn_arr[i], i + NB_BTN_TOP);
        sfSprite_setScale(btn_arr[i]->btn_sprite,
            (sfVector2f){.x = 0.1, .y = 0.1});
        sfSprite_setScale(btn_arr[i]->btn_image,
            (sfVector2f){.x = 0.2, .y = 0.2});
    }
    sfSprite_setPosition(btn_arr[0]->btn_sprite, (sfVector2f){20, 960});
    sfSprite_setPosition(btn_arr[1]->btn_sprite, (sfVector2f){120, 960});
    sfSprite_setPosition(btn_arr[0]->btn_image, (sfVector2f){25, 960});
    sfSprite_setPosition(btn_arr[1]->btn_image, (sfVector2f){125, 960});
    game->bottom_buttons = btn_arr;
}
