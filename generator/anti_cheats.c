/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** anti_cheats
*/

#include "mylib.h"
#include <time.h>

int random_value(int lower, int upper, int max, int *alea)
{
    int i = 0;

    i = alea[rand() % max + (0 + 1)];
    return (i);
}

void anti_cheat_2(maze_t *maze)
{
    int x = 0;
    int y = 1;
    int stop = 0;

    while (y != maze->col)
    {
        if (maze->maze[y][x] != '*')
            stop = 1;
        y++;
    }
    if (stop == 0)
        maze->maze[maze->col][x] = 'X';
}

void anti_cheat(maze_t *maze)
{
    int y = 0;
    int x = 1;
    int stop = 0;

    while (x != maze->row && stop == 0)
    {
        if (maze->maze[y][x] != '*')
            stop = 1;
        x++;
    }
    if (stop == 1)
        anti_cheat_2(maze);
    else if (stop == 0)
    {
        maze->maze[y][maze->row] = 'X';
        anti_cheat_2(maze);
    }
}

void maze_stuck_dir2(maze_t *maze, cursor_t *c)
{
    if (c->x <= maze->row - 2 && maze->maze[c->y][c->x + 1] == '*'
    && maze->maze[c->y][c->x + 2] == '*' &&
    maze->maze[c->y][c->x + 2] != 'O') {
        c->good_value_tab[c->gv_tab] = 2;
        c->gv_tab++;
    }
    else
        c->stuck_right = 1;
    if (c->y <= maze->col - 2 && maze->maze[c->y + 1][c->x] == '*'
    && maze->maze[c->y + 2][c->x] == '*' &&
    maze->maze[c->y + 2][c->x] != 'O')
    {
        c->good_value_tab[c->gv_tab] = 3;
        c->gv_tab++;
    }
    else
        c->stuck_down = 1;
}

void maze_stuck_dir(maze_t *maze, cursor_t *c)
{
    c->good_value_tab = malloc(sizeof(int) * 5);
    c->gv_tab = 0;
    if (c->x >= 2 && maze->maze[c->y][c->x - 1] == '*' &&
    maze->maze[c->y][c->x - 2] == '*' &&
    maze->maze[c->y][c->x - 2] != 'O') {
        c->good_value_tab[c->gv_tab] = 0;
        c->gv_tab++;
    }
    else
        c->stuck_left = 1;
    if (c->y >= 2 && maze->maze[c->y - 1][c->x] == '*' &&
    maze->maze[c->y - 2][c->x] == '*' &&
    maze->maze[c->y - 2][c->x] != 'O') {
        c->good_value_tab[c->gv_tab] = 1;
        c->gv_tab++;
    }
    else
        c->stuck_up = 1;
    maze_stuck_dir2(maze, c);
}