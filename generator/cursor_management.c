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

int cursor_stop(maze_t *maze, int stop)
{
    for (int nb = 0; maze->cursor[nb] != NULL; nb++) {
        if (maze->cursor[nb]->stop == 1) {
            if (maze->cursor[nb]->free_stop == 0) {
                free_strtab(maze->cursor[nb]->pos);
                maze->cursor[nb]->free_stop = 1;
            }
            stop++;
        }
    }
    return stop;
}

int cursor_move(maze_t *maze, int random)
{
    int stop = 0;

    for (int nb = 0; maze->cursor[nb] != NULL; nb++) {
        if (maze->cursor[nb]->stop != 1) {
            maze_stuck(maze, maze->cursor[nb]);
            maze->cursor[nb]->alea = binare_tab_spec
            (maze->cursor[nb]->good_value_tab, 380);
            random = random_value(0, 3, 100, maze->cursor[nb]->alea);
            free(maze->cursor[nb]->good_value_tab);
            choose_dir(maze, maze->cursor[nb], random);
            case_stuck(maze, maze->cursor[nb]);
            free(maze->cursor[nb]->alea);
        }
    }
    return (cursor_stop(maze, stop));
}