/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** mouse_click.c
*/
#include "my_world.h"
#include <stdio.h>

static void change_vertx(game_t *game, unsigned int i, unsigned int j)
{
    if (game->mode->down && (!game->mode->up && !game->mode->reset))
        game->map3d[i][j] -= 1;
    if (game->mode->up && (!game->mode->down && !game->mode->reset))
        game->map3d[i][j] += 1;
    if (game->mode->reset)
        game->map3d[i][j] = 0;
}

static void try_get_new_tile
(unsigned int bool, game_t *game, unsigned int i, unsigned int j)
{
    if (bool == 1) {
        change_vertx(game, i, j);
    }
}

static unsigned int check_dist(sfMouseButtonEvent *mouse, sfVector2f *vertx)
{
    sfVector2f dist_vect = {0, 0};
    unsigned int dist = 0;

    dist_vect.x = vertx->x - mouse->x;
    dist_vect.y = vertx->y - mouse->y;
    dist = sqrt(pow(dist_vect.x, 2) + pow(dist_vect.y, 2));
    if (dist < 10)
        return 1;
    return 0;
}

static void check_mouse_on_vrtx
(sfMouseButtonEvent *mouse, game_t *game)
{
    sfVector2f **map2d = create_2d_map(game, game->map3d);

    for (unsigned int i = 0; i < game->mapsize.x; ++i) {
        for (unsigned int j = 0; j < game->mapsize.y; ++j) {
            try_get_new_tile(check_dist(mouse, &(map2d[i][j])),
                game, i, j);
        }
    }
    destroy_2d_map(&(game->mapsize), map2d);
}

static void change_build_mode(game_t *game, int i)
{
    if (i == 0 && game->mode->reset == 0)
        game->mode->reset = 1;
    else
        game->mode->reset = 0;
    if (i == 1 && game->mode->up == 0)
        game->mode->up = 1;
    else
        game->mode->up = 0;
    if (i == 2 && game->mode->down == 0)
        game->mode->down = 1;
    else
        game->mode->down = 0;
}

static void check_change_map_size(unsigned int i, game_t *game)
{
    if (i == 0 && (game->mapsize.x > 2 && game->mapsize.y > 2)) {
        change_map_size(game,
            &(sfVector2u){.x = game->mapsize.x - 1, .y = game->mapsize.y - 1});
    }
    if (i == 1) {
        change_map_size(game,
            &(sfVector2u){.x = game->mapsize.x + 1, .y = game->mapsize.y + 1});
    }
}

static void check_mouse_on_bot_btn(game_t *game, sfMouseButtonEvent *mouse)
{
    sfVector2i vec = {.x = mouse->x, .y = mouse->y};
    sfVector2f vec_btn;

    for (unsigned int i = 0; i < NB_BTN_BOT; ++i) {
        vec_btn = sfSprite_getPosition(game->bottom_buttons[i]->btn_sprite);
        if (check_coll(game->bottom_buttons[i], &vec, &vec_btn) == 1) {
            sfSprite_setTexture(game->bottom_buttons[i]->btn_sprite,
                game->bottom_buttons[i]->click, sfFalse);
            check_change_map_size(i, game);
        }
    }
}

static void check_mouse_on_buttons(game_t *game, sfMouseButtonEvent *mouse)
{
    sfVector2i vec = {.x = mouse->x, .y = mouse->y};
    sfVector2f vec_btn;
    int i = 0;

    while (i < NB_BTN_TOP) {
        vec_btn = sfSprite_getPosition(game->top_buttons[i]->btn_sprite);
        if (check_coll(game->top_buttons[i], &vec, &vec_btn) == 1) {
            sfSprite_setTexture(game->top_buttons[i]->btn_sprite,
                game->top_buttons[i]->click, sfFalse);
            reset_button_states(game->top_buttons, i);
            change_build_mode(game, i);
        }
        i++;
    }
    check_mouse_on_bot_btn(game, mouse);
}

void manage_mouse_click(sfMouseButtonEvent *mouse, game_t *game)
{
    check_mouse_on_vrtx(mouse, game);
    check_mouse_on_buttons(game, mouse);
    return;
}
