/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** bs_my_world.c
*/
#include "my_world.h"

static int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; ++i) {
        if (s1[i] - s2[i] != 0) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    game_t *game = NULL;

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return help();
    if (argc != 1)
        return 84;
    game = init_game();
    sfMusic_setLoop(game->music, sfFalse);
    sfMusic_play(game->music);
    while (sfRenderWindow_isOpen(game->window))
        game_loop(game);
    free_ressources(game);
    return 0;
}
