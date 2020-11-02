/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** build
*/

#include <time.h>
#include "mylib.h"

void case_stuck(maze_t *maze, cursor_t *c)
{
    int i = 0;
    if (c->stuck == 1)
    {
        reset_stuck(maze, c);
        i = cut_pos_maze(maze, c);
        if (i != 0)
        {
            c->y = my_putint(c->pos[i]);
            c->x = my_putint(c->pos[i - 2]);
        }
    }
}

void choose_dir(maze_t *maze, cursor_t *c, int random)
{
    if (random == 0)
        left_management(maze, c);
    if (random == 1)
        up_management(maze, c);
    if (random == 2)
        right_management(maze, c);
    if (random == 3)
        down_management(maze, c);
}

void def_value_build_walls(maze_t *maze)
{
    maze->row -= 1;
    maze->col -= 1;
}

void build_walls(maze_t *maze)
{
    int random = 0;
    char *input = NULL;
    int stop = 0;

    def_value_build_walls(maze);
    srand(time(NULL));
    while (stop != maze->nbcursor) {
        stop = cursor_move(maze, random);
        free(input);
    }
    if (maze->perfect == 0) {
        for (int y = 0; y != my_strlen_array(maze->maze); y++) {
            maze->maze[y][0] = '*';
            maze->maze[y][1] = '*';
        }
    }
}