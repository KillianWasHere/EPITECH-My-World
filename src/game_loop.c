/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** game_loop.c
*/
#include "my_world.h"

static void check_key_move(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        game->view->coords.x += 5;
    if (sfKeyboard_isKeyPressed(sfKeyRight) && game->view->coords.x > 5)
        game->view->coords.x -= 5;
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        game->view->coords.y += 5;
    if (sfKeyboard_isKeyPressed(sfKeyDown) && game->view->coords.y > 5)
        game->view->coords.y -= 5;
}

static void check_key_angle(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyS) && game->view->angle.y < 10)
        game->view->angle.y += 1;
    if (sfKeyboard_isKeyPressed(sfKeyZ) && game->view->angle.y > 0)
        game->view->angle.y -= 1;
    if (sfKeyboard_isKeyPressed(sfKeyQ) && game->view->angle.x < 20)
        game->view->angle.x += 1;
    if (sfKeyboard_isKeyPressed(sfKeyD) && game->view->angle.x > 0)
        game->view->angle.x -= 1;
}

static void check_key_zoom(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyI) && game->view->zoom < UINT_MAX)
        game->view->zoom += 1;
    if (sfKeyboard_isKeyPressed(sfKeyO) && game->view->zoom > 0)
        game->view->zoom -= 1;
}

static void process_time(game_t *game)
{
    sfTime time;
    unsigned int seconds = 0;

    time = sfClock_getElapsedTime(game->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 1 / 60) {
        sfClock_restart(game->clock);
    }
}

static void analyse_event(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &(game->event))) {
        if (game->event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(game->window);
        check_key_move(game);
        check_key_zoom(game);
        check_key_angle(game);
        if (game->event.type == sfEvtMouseButtonPressed)
            manage_mouse_click(&game->event.mouseButton, game);
    }
}

void game_loop(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    process_time(game);
    analyse_event(game);
    DRAW_SPRITE(game->window, game->bg->bg_sprite);
    draw_map(game);
    for (int i = 0; i < NB_BTN_TOP; i++) {
        DRAW_SPRITE(game->window, game->top_buttons[i]->btn_sprite);
        DRAW_SPRITE(game->window, game->top_buttons[i]->btn_image);
    }
    for (int i = 0; i < NB_BTN_BOT; i++) {
        DRAW_SPRITE(game->window, game->bottom_buttons[i]->btn_sprite);
        DRAW_SPRITE(game->window, game->bottom_buttons[i]->btn_image);
    }
    check_if_button_are_hooverd(game);
    sfRenderWindow_display(game->window);
}
