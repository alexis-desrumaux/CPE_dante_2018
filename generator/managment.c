/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** managment
*/

#include "mylib.h"
#include <time.h>

int maze_stuck(maze_t *maze, cursor_t *cursor)
{
    maze_stuck_dir(maze, cursor);
    if (cursor->stuck_left == 1 && cursor->stuck_up == 1 &&
    cursor->stuck_right == 1 && cursor->stuck_down == 1) {
        cursor->stuck = 1;
    }
    else {
        cursor->stuck_left = 0;
        cursor->stuck_up = 0;
        cursor->stuck_right = 0;
        cursor->stuck_down = 0;
    }
    return (0);
}

int down_management(maze_t *maze, cursor_t *c)
{
    if (c->y <= maze->col - 2 && maze->maze[c->y + 1][c->x] == '*'
    && maze->maze[c->y + 2][c->x] == '*'
    && maze->maze[c->y + 2][c->x] != 'O') {
        c->y += 1;
        maze->maze[c->y][c->x] = 'X';
        c->y += 1;
        maze->maze[c->y][c->x] = 'X';
        for (int i = 0; i != 5; i++)
            c->pos = re_malloc_strtab(c->pos);
        c->pos = to_strtab_char(c->pos, "x");
        c->pos = to_strtab_int(c->pos, c->x);
        c->pos = to_strtab_char(c->pos, "y");
        c->pos = to_strtab_int(c->pos, c->y);
    } else {
        if (c->stuck_down == 0)
            c->stuck_down++;
    }
    return (0);
}

int right_management(maze_t *maze, cursor_t *c)
{
    if (c->x <= maze->row - 2 && maze->maze[c->y][c->x + 1] == '*'
    && maze->maze[c->y][c->x + 2] == '*'
    && maze->maze[c->y][c->x + 2] != 'O') {
        c->x += 1;
        maze->maze[c->y][c->x] = 'X';
        c->x += 1;
        maze->maze[c->y][c->x] = 'X';
        for (int i = 0; i != 5; i++)
            c->pos = re_malloc_strtab(c->pos);
        c->pos = to_strtab_char(c->pos, "x");
        c->pos = to_strtab_int(c->pos, c->x);
        c->pos = to_strtab_char(c->pos, "y");
        c->pos = to_strtab_int(c->pos, c->y);

    } else {
        if (c->stuck_right == 0)
            c->stuck_right++;
    }
    return (0);
}

int up_management(maze_t *maze, cursor_t *c)
{
    if (c->y >= 2 && maze->maze[c->y - 1][c->x] == '*'
    && maze->maze[c->y - 2][c->x] == '*' &&
    maze->maze[c->y - 2][c->x] != 'O') {
        c->y -= 1;
        maze->maze[c->y][c->x] = 'X';
        c->y -= 1;
        maze->maze[c->y][c->x] = 'X';
        for (int i = 0; i != 5; i++)
            c->pos = re_malloc_strtab(c->pos);
        c->pos = to_strtab_char(c->pos, "x");
        c->pos = to_strtab_int(c->pos, c->x);
        c->pos = to_strtab_char(c->pos, "y");
        c->pos = to_strtab_int(c->pos, c->y);
    } else {
        if (c->stuck_up == 0)
            c->stuck_up++;
    }
    return (0);
}

int left_management(maze_t *maze, cursor_t *c)
{
    if (c->x >= 2 && maze->maze[c->y][c->x - 1] == '*'
    && maze->maze[c->y][c->x - 2] == '*' &&
    maze->maze[c->y][c->x - 2] != 'O') {
        c->x -= 1;
        maze->maze[c->y][c->x] = 'X';
        c->x -= 1;
        maze->maze[c->y][c->x] = 'X';
        for (int i = 0; i != 5; i++)
            c->pos = re_malloc_strtab(c->pos);
        c->pos = to_strtab_char(c->pos, "x");
        c->pos = to_strtab_int(c->pos, c->x);
        c->pos = to_strtab_char(c->pos, "y");
        c->pos = to_strtab_int(c->pos, c->y);
    } else {
        if (c->stuck_left == 0)
            c->stuck_left++;
    }
    return (0);
}