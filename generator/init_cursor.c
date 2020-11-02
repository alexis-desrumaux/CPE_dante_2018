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

cursor_t *cursor_gen(int i, int col, int rowmax, int colmax)
{
    cursor_t *cursor = malloc(sizeof(cursor_t));

    cursor->stuck_down = 0;
    cursor->stuck_left = 0;
    cursor->stuck_right = 0;
    cursor->stuck_up = 0;
    cursor->stuck = 0;
    cursor->i_pos = 0;
    cursor->x = i;
    cursor->y = col;
    cursor->pos = define_strtab(sizeof(char *) * 5);
    cursor->alea = NULL;
    cursor->stop = 0;
    cursor->free_stop = 0;
    return (cursor);
}

void count_nb_cursor_and_malloc(maze_t *maze)
{
    int row = maze->row - 1;
    int col = maze->col - 1;
    int i = row;
    int n = col - 1;
    int nbstruct = 0;

    for (; n >= 0; n -= 20) {
        for (; i >= 0; i -= 4) {
            nbstruct++;
        }
        i = row;
    }
    maze->cursor = malloc(sizeof(cursor_t *) * (nbstruct + 1));
    maze->nbcursor = nbstruct;
}

void create_cursor_struct(maze_t *maze)
{
    int row = maze->row - 1;
    int col = maze->col - 1;
    int i = row;
    int n = col - 1;
    int j = 0;

    count_nb_cursor_and_malloc(maze);
    for (; n >= 0; n -= 20) {
        for (; i >= 0; i -= 4) {
            maze->cursor[j] = cursor_gen(i, n, row, col);
            j++;
        }
        i = row;
    }
    maze->cursor[j] = NULL;
}