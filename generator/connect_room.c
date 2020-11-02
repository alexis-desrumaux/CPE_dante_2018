/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** connect_room
*/

#include "mylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int my_stuck_four(goodway_t *good, char **pos, int i, int len_array)
{
    if (my_strlen_array(good->pos) == 2) {
        good->x = 0;
        good->y = 0;
        if (goodway_stuck(good) == 4)
            return (1);
    } else {
        pos = define_strtab(sizeof(char *) * (good->row * good->col));
        while (i != len_array) {
            pos = to_strtab_char(pos, good->pos[i]);
            i++;
        }
        free_strtab(good->pos);
        good->pos = pos;
        good->x = my_putint(good->pos[my_strlen_array(good->pos) - 2]);
        good->y = my_putint(good->pos[my_strlen_array(good->pos) - 1]);
    }
    return (0);
}

int case_stuck_goodway(goodway_t *good, int stuck)
{
    char **pos = NULL;
    int i = 0;
    int len_array = my_strlen_array(good->pos) - 2;

    if (stuck == 4) {
        if (my_stuck_four(good, pos, i, len_array) == 1)
            return 1;
    }
    return (0);
}

void check_x(goodway_t *good, int random)
{
    if (random == 0 && good->x != 0 && good->maze[good->y][good->x - 1] != 'X'
    && good->maze[good->y][good->x - 1] != 'a') {
        good->x -= 1;
        add_pos_goodway(good);
    }
    if (random == 2 && good->x != good->row && good->maze[good->y][good->x + 1]
    != 'X' && good->maze[good->y][good->x + 1] != 'a') {
        good->x += 1;
        add_pos_goodway(good);
    }
}

void check_y(goodway_t *good, int random)
{
    if (random == 1 && good->y != 0 && good->maze[good->y - 1][good->x] != 'X'
    && good->maze[good->y - 1][good->x] != 'a') {
        good->y -= 1;
        add_pos_goodway(good);
    }
    if (random == 3 && good->y != good->col && good->maze[good->y + 1][good->x]
    != 'X' && good->maze[good->y + 1][good->x] != 'a') {
        good->y += 1;
        add_pos_goodway(good);
    }

}

void connect_room(goodway_t *goodway)
{
    int random = 0;
    int stuck = 0;
    int stop = 0;

    goodway->alea = NULL;
    goodway->alea = binare_tab(0, 3, 300);
    goodway->pos = NULL;
    goodway->pos = define_strtab(sizeof(char *) *
    (goodway->row * goodway->col));
    while (stop != 1) {
        stuck = goodway_stuck(goodway);
        random = random_value(0, 3, 100, goodway->alea);
        check_x(goodway, random);
        check_y(goodway, random);
        goodway->maze[goodway->y][goodway->x] = 'a';
        stop = case_stuck_goodway(goodway, stuck);
    }
}