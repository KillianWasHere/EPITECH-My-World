/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** change_map_size.c
*/
#include "my_world.h"
#include <stdio.h>

int check_coll(buttons_t *btn, sfVector2i *p_a, sfVector2f *p_b)
{
    sfVector2f vec = sfSprite_getScale(btn->btn_sprite);
    const sfTexture *texture = sfSprite_getTexture(btn->btn_sprite);
    sfVector2u texture_size = sfTexture_getSize(texture);

    if (p_a->x == p_b->x) {
        return 0;
    }
    if (p_a->x >= p_b->x && p_a->x <= p_b->x + (texture_size.x * vec.x) &&
        p_a->y >= p_b->y && p_a->y <= p_b->y + (texture_size.y * vec.y)) {
        return 1;
    }
    return 0;
}

static void modify_texture(buttons_t *btn)
{
    if (btn->state == 0)
        sfSprite_setTexture(btn->btn_sprite, btn->normal, sfFalse);
    if (btn->state == 1)
        sfSprite_setTexture(btn->btn_sprite, btn->click, sfFalse);
}

void reset_button_states(buttons_t **buttons, int i)
{
    int index = 0;

    if (buttons[i]->state == 1) {
        buttons[i]->state = 0;
        return;
    }
    while (index < NB_BTN_TOP) {
        if (buttons[index]->state != 0)
            buttons[index]->state = 0;
        index++;
    }
    buttons[i]->state = 1;
}

static void set_text(game_t *game, int i)
{
    if (i == 0)
        sfText_setString(game->infobox[i]->help_text, "Reset terrain height");
    if (i == 1)
        sfText_setString(game->infobox[i]->help_text, "Incease terrain height");
    if (i == 2)
        sfText_setString(game->infobox[i]->help_text, "Reduce terrain height");
    if (i == 3)
        sfText_setString(game->infobox[i]->help_text, "Reduce map size");
    if (i == 4)
        sfText_setString(game->infobox[i]->help_text, "Increase map size");
}

static void check_bot_btn_hooverd
(sfVector2f *vec_btn, sfVector2i *vec_mouse, game_t *game)
{
    for (unsigned int i = 0; i < NB_BTN_BOT; ++i) {
        *vec_btn = sfSprite_getPosition(game->bottom_buttons[i]->btn_sprite);
        if (check_coll(game->bottom_buttons[i], vec_mouse, vec_btn) == 1) {
            set_text(game, i + NB_BTN_TOP);
            sfSprite_setTexture(game->bottom_buttons[i]->btn_sprite,
                game->bottom_buttons[i]->hoover, sfFalse);
            sfRenderWindow_drawText(game->window,
                game->infobox[i + NB_BTN_TOP]->help_text, NULL);
        } else {
            modify_texture(game->bottom_buttons[i]);
        }
    }
}

void check_if_button_are_hooverd(game_t *game)
{
    sfVector2i vec_mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f vec_btn;

    for (unsigned int i = 0; i < NB_BTN_TOP; ++i) {
        vec_btn = sfSprite_getPosition(game->top_buttons[i]->btn_sprite);
        if (check_coll(game->top_buttons[i], &vec_mouse, &vec_btn) == 1) {
            set_text(game, i);
            sfSprite_setTexture(game->top_buttons[i]->btn_sprite,
                game->top_buttons[i]->hoover, sfFalse);
            sfRenderWindow_drawText(game->window,
                game->infobox[i]->help_text, NULL);
        } else {
            modify_texture(game->top_buttons[i]);
        }
    }
    check_bot_btn_hooverd(&vec_btn, &vec_mouse, game);
}
