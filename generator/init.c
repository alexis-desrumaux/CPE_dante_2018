/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** init
*/

#include "mylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int goodway_stuck(goodway_t *goodway)
{
    int stuck = 0;

    if (is_stuck_dir(goodway, -1, 0) == 1)
        stuck++;
    if (is_stuck_dir(goodway, 0, -1) == 1)
        stuck++;
    if (is_stuck_dir(goodway, 1, 0) == 1)
        stuck++;
    if (is_stuck_dir(goodway, 0, 1) == 1)
        stuck++;
    return (stuck);
}

void redefine_struct_goodway(goodway_t *goodway)
{
    goodway->goodway_x = define_strtab(sizeof(char *) * goodway->row *
    goodway->col * 2);
    goodway->goodway_y = define_strtab(sizeof(char *) * goodway->row *
    goodway->col * 2);
    goodway->random_potential_way = NULL;
}

void free_while_goodway(goodway_t *goodway)
{
    free(goodway->random_potential_way);
    free_strtab(goodway->goodway_x);
    free_strtab(goodway->goodway_y);
    free(goodway->alea);
    free_strtab(goodway->pos);
}

void play_goodway_maze(goodway_t *goodway, maze_t *maze, int random)
{
    goodway->random_potential_way = NULL;
    while (count_badway(goodway->maze) != 0) {
        connect_room(goodway);
        count_goodway(goodway);
        if (count_badway(goodway->maze) != 0)
            case_badway(goodway, random);
    }
}

void goodway_maze(maze_t *maze)
{
    goodway_t *goodway = malloc(sizeof(goodway_t));
    int random = 0;

    if (goodway == NULL) {
        free(goodway);
        return ;
    }
    goodway->maze = cp_strtab(maze->maze, (maze->row * maze->col) * 2);
    goodway->row = maze->row;
    goodway->col = maze->col;
    goodway->x = 0;
    goodway->y = 0;
    goodway->goodway_x = define_strtab(sizeof(char *) *
    goodway->row * goodway->col * 2);
    goodway->goodway_y = define_strtab(sizeof(char *) *
    goodway->row * goodway->col * 2);
    play_goodway_maze(goodway, maze, random);
    delete_all_a_symbol(goodway->maze);
    print_strtab(goodway->maze, '\n');
    free_goodway_struct(goodway);
}