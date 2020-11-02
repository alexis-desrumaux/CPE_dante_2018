/*
** EPITECH PROJECT, 2019
** goodway.c
** File description:
** goodway.c
*/

#include "mylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int count_badway(char **maze)
{
    int i = 0;
    int j = 0;
    int count_star = 0;

    while (maze[i] != NULL) {
        while (maze[i][j] != '\0') {
            if (maze[i][j] == '*')
                count_star++;
            j++;
        }
        j = 0;
        i++;
    }
    return (count_star);
}

int count_goodway(goodway_t *goodway)
{
    int i = 0;
    int j = 0;
    int count_a = 0;

    while (goodway->maze[i] != NULL) {
        while (goodway->maze[i][j] != '\0') {
            if (goodway->maze[i][j] == 'a') {
                count_a++;
                potential_way_count(goodway, i, j);
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (count_a);
}

int is_stuck_dir_next(goodway_t *goodway, int xdir, int ydir, int check)
{
    if (check == 0) {
        if (goodway->maze[goodway->y + ydir][goodway->x + xdir] == 'X')
            check = 1;
        if (goodway->maze[goodway->y + ydir][goodway->x + xdir] == 'a')
            check = 1;
    }
    return (check);
}

int is_stuck_dir(goodway_t *goodway, int xdir, int ydir)
{
    int check = 0;

    if (goodway->x == 0 && goodway->x + xdir < 0)
        check = 1;
    if (goodway->x == goodway->row && goodway->x + xdir > goodway->row)
        check = 1;
    if (goodway->y == 0 && goodway->y + ydir < 0)
        check = 1;
    if (goodway->y == goodway->col && goodway->y + ydir > goodway->col)
        check = 1;
    check = is_stuck_dir_next(goodway, xdir, ydir, check);
    return (check);
}

void add_pos_goodway(goodway_t *goodway)
{
    goodway->pos = to_strtab_int(goodway->pos, goodway->x);
    goodway->pos = to_strtab_int(goodway->pos, goodway->y);
}