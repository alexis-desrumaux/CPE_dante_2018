/*
** EPITECH PROJECT, 2019
** ALEXIS DESRUMAUX
** File description:
** file.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "mylib.h"

int begin_generator(maze_t *maze, int argc, char **argv)
{
    init(maze, argv);
    if (isnumber(argv[1]) == 1 && isnumber(argv[2]) == 1) {
        if (my_putint(argv[1]) < 3 || my_putint(argv[2]) < 3)
            return (84);
        full_wall(argc, argv, maze);
        if (maze->perfect == 1)
            anti_cheat(maze);
        free_cursor(maze->cursor);
        goodway_maze(maze);
        free_maze_struct(maze);
    } else
        return (84);
    return (0);
}