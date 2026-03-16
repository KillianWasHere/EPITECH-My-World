/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** help.c
*/
#include <unistd.h>

int help(void)
{
    write(1, "A terraformer program\nUSAGE\n", 28);
    write(1, "  ./my_world [OPTIONS]\n", 23);
    write(1, "OPTIONS\n  -h\tprint the usage and quit.\n", 39);
    write(1, "USER INTERACTIONS\n", 18);
    write(1, "'escape' key\tquit the game and end the program.\n", 48);
    write(1, "'arrows' key\tmove around in the map.\n", 37);
    write(1, "'ZQSD' keys\tchange the angle of view.\n", 38);
    return 0;
}
