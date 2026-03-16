/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** draw_map.c
*/
#include <stdio.h>
#include "my_world.h"
#include <stddef.h>

static sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfBlack};
    sfVertex vertex2 = {.position = *point2, .color = sfBlack};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLines);
    return vertex_array;
}

static sfVertexArray *create_point(sfVector2f *point1)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfRed};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_setPrimitiveType(vertex_array, sfPoints);
    return vertex_array;
}

static sfVertexArray *create_triangle(sfVector2f *point1, sfVector2f *point2,
    sfVector2f *point3)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1,
        .texCoords = {0.0, 0.0}, .color = sfWhite};
    sfVertex vertex2 = {.position = *point2,
        .texCoords = {200.0, 0.0}, .color = sfWhite};
    sfVertex vertex3 = {.position = *point3,
        .texCoords = {0.0, 200.0}, .color = sfWhite};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_setPrimitiveType(vertex_array, sfTriangles);
    return vertex_array;
}

static void draw_lines
(game_t *game, unsigned int i, unsigned int j, sfVector2f **map2d)
{
    sfVertexArray *vertx_arr = NULL;

    if (i + 1 < game->mapsize.x) {
        vertx_arr = create_line(&(map2d[i][j]), &(map2d[i + 1][j]));
        sfRenderWindow_drawVertexArray(game->window, vertx_arr, NULL);
        sfVertexArray_destroy(vertx_arr);
    }
    if (j + 1 < game->mapsize.y) {
        vertx_arr = create_line(&(map2d[i][j]), &(map2d[i][j + 1]));
        sfRenderWindow_drawVertexArray(game->window, vertx_arr, NULL);
        sfVertexArray_destroy(vertx_arr);
    }
}

static void draw_points
(game_t *game, unsigned int i, unsigned int j, sfVector2f **map2d)
{
    sfVertexArray *point_arr = NULL;

    point_arr = create_point(&(map2d[i][j]));
    sfRenderWindow_drawVertexArray(game->window, point_arr, NULL);
    sfVertexArray_destroy(point_arr);
}

static void draw_triangle
(game_t *game, unsigned int i, unsigned int j, sfVector2f **map2d)
{
    sfVertexArray *triangle_arr = NULL;
    sfRenderStates state;

    state.blendMode = sfBlendAlpha;
    state.transform = sfTransform_Identity;
    state.texture = game->game_textures->grass;
    state.shader = NULL;
    if (i + 1 < game->mapsize.x && j + 1 < game->mapsize.y) {
        triangle_arr = create_triangle(&(map2d[i][j]),
            &(map2d[i + 1][j]), &(map2d[i][j + 1]));
        sfRenderWindow_drawVertexArray(game->window, triangle_arr, &state);
        sfVertexArray_destroy(triangle_arr);
    }
    if (i + 1 < game->mapsize.x && j + 1 < game->mapsize.y) {
        triangle_arr = create_triangle(&(map2d[i + 1][j + 1]),
            &(map2d[i + 1][j]), &(map2d[i][j + 1]));
        sfRenderWindow_drawVertexArray(game->window, triangle_arr, &state);
        sfVertexArray_destroy(triangle_arr);
    }
}

void draw_map(game_t *game)
{
    sfVector2f **map2d = create_2d_map(game, game->map3d);

    for (unsigned int i = 0; i < game->mapsize.x; ++i) {
        for (unsigned int j = 0; j < game->mapsize.y; ++j) {
            draw_lines(game, i, j, map2d);
            draw_points(game, i, j, map2d);
            draw_triangle(game, i, j, map2d);
        }
    }
    destroy_2d_map(&(game->mapsize), map2d);
}
