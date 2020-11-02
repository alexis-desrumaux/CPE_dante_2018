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

int case_not_zero(maze_t *maze, cursor_t *c, int end, char **pos_cpy)
{
    int i = 0;

    while (i != end)
    {
        pos_cpy = to_strtab_char(pos_cpy, c->pos[i]);
        i++;
    }
    free_strtab(c->pos);
    c->pos = pos_cpy;
    return (i - 1);
}

int cut_pos_maze(maze_t *maze, cursor_t *c)
{
    char **pos_cpy = define_strtab((maze->row * maze->col) * 6);
    int end = my_strlen_array(c->pos) - 4;

    if (end != 0)
        return (case_not_zero(maze, c, end, pos_cpy));
    if (end == 0)
    {
        free_strtab(pos_cpy);
        c->stop = 1;
        return (0);
    }
    return (0);
}