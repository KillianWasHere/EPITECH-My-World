/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** map.c
*/
#include "my_world.h"

static sfVector2f project_iso_point(game_t *game, int x, int y, int z)
{
    sfVector2f point = {
        (cos(DEG2RAD(game->view->angle.x)) * x -
            cos(DEG2RAD(game->view->angle.x)) * y) *
        game->view->zoom + game->view->coords.x,
        (sin(DEG2RAD(game->view->angle.y)) * y +
            sin(DEG2RAD(game->view->angle.y)) * x - z) *
        game->view->zoom + game->view->coords.y};

    return point;
}

sfVector2f **create_2d_map(game_t *game, int **map3d)
{
    sfVector2f **map = malloc(game->mapsize.x * sizeof(sfVector2f *));

    for (unsigned int i = 0; i < game->mapsize.x; ++i) {
        map[i] = malloc(game->mapsize.y * sizeof(sfVector2f));
        for (unsigned int j = 0; j < game->mapsize.y; ++j) {
            map[i][j] = project_iso_point(game, i, j, map3d[i][j]);
        }
    }
    return map;
}

void destroy_2d_map(sfVector2u *size, sfVector2f **map2d)
{
    for (unsigned int i = 0; i < size->x; ++i) {
        free(map2d[i]);
    }
    free(map2d);
}
