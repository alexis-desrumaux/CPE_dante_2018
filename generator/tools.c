/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** tools
*/

#include "mylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void free_goodway_struct(goodway_t *goodway)
{
    free_strtab(goodway->maze);
    free(goodway->alea);
    free_strtab(goodway->pos);
    free(goodway);
}

char **cp_strtab(char **origin, int malloc_v)
{
    char **tab_cpy = define_strtab(malloc_v);
    int i = 0;

    while (origin[i] != NULL) {
        tab_cpy = to_strtab_char(tab_cpy, origin[i]);
        i++;
    }
    return (tab_cpy);
}

void delete_all_a_symbol(char **maze)
{
    int i = 0;
    int j = 0;

    while (maze[i] != NULL) {
        while (maze[i][j] != '\0') {
            if (maze[i][j] == 'a') {
                maze[i][j] = '*';
            }
            j++;
        }
        j = 0;
        i++;
    }
}

void brick_wall(int random, goodway_t *goodway)
{

    goodway->maze[my_putint(goodway->goodway_y[random])]
    [my_putint(goodway->goodway_x[random])] = 'a';
    goodway->x = my_putint(goodway->goodway_x[random]);
    goodway->y = my_putint(goodway->goodway_y[random]);
}

void potential_way_count(goodway_t *good, int y, int x)
{
    if (x > 1 && good->maze[y][x - 1] == 'X' && good->maze[y][x - 2] == '*') {
        good->goodway_x = to_strtab_int(good->goodway_x, x - 1);
        good->goodway_y = to_strtab_int(good->goodway_y, y);
    }
    if (x < good->row - 1 && good->maze[y][x + 1] == 'X' &&
    good->maze[y][x + 2] == '*') {
        good->goodway_x = to_strtab_int(good->goodway_x, x + 1);
        good->goodway_y = to_strtab_int(good->goodway_y, y);
    }
    if (y > 1 && good->maze[y - 1][x] == 'X' && good->maze[y - 2][x] == '*') {
        good->goodway_x = to_strtab_int(good->goodway_x, x);
        good->goodway_y = to_strtab_int(good->goodway_y, y - 1);
    }
    if (y < good->col - 1 && good->maze[y + 1][x] == 'X' &&
    good->maze[y + 2][x] == '*') {
        good->goodway_x = to_strtab_int(good->goodway_x, x);
        good->goodway_y = to_strtab_int(good->goodway_y, y + 1);
    }
}
