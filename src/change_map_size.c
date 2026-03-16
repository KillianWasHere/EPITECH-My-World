/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** change_map_size.c
*/
#include "my_world.h"

static void free_current_map3d(game_t *game)
{
    for (unsigned int i = 0; i < game->mapsize.x; ++i) {
        free(game->map3d[i]);
    }
    free(game->map3d);
    game->map3d = NULL;
}

void change_map_size(game_t *game, sfVector2u *new_size)
{
    sfVector2u old_size = {.x = game->mapsize.x, .y = game->mapsize.y};
    int **old_map = game->map3d;
    int **new_map = malloc(new_size->x * sizeof(int *));

    for (unsigned int i = 0; i < new_size->x; ++i) {
        new_map[i] = malloc(new_size->y * sizeof(int));
        for (unsigned int j = 0; j < new_size->y; ++j) {
            new_map[i][j] = 0;
        }
    }
    for (unsigned int i = 0; i < MIN(old_size.x, new_size->x); ++i) {
        for (unsigned int j = 0; j < MIN(old_size.y, new_size->y); ++j) {
            new_map[i][j] = old_map[i][j];
        }
    }
    free_current_map3d(game);
    game->map3d = new_map;
    game->mapsize.x = new_size->x;
    game->mapsize.y = new_size->y;
}
