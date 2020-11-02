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

int has_start_finish(solver_t *solver)
{
    solver->len_x = my_strlen(solver->maze[0]) - 1;
    solver->len_y = my_strlen_array(solver->maze) - 1;
    if (solver->maze[0][0] == 'X' ||
    solver->maze[solver->len_y][solver->len_x] == 'X') {
        my_putstr("no solution found\n");
        return (84);
    }
    return (0);
}

int has_good_symbol(solver_t *solver)
{
    int stop = 0;

    for (int i = 0; stop != 1 && solver->maze[i] != NULL; i++) {
        for (int j = 0; solver->maze[i][j] != '\0'; j++) {
            if (solver->maze[i][j] != 'X' && solver->maze[i][j] != '*')
                stop = 1;
        }
    }
    if (stop == 1)
        return (84);
    return (0);
}

int check_symbol_and_initialisation(solver_t *solver)
{
    if (has_good_symbol(solver) == 84)
        return (84);
    if (has_start_finish(solver) == 84)
        return (84);
    return 0;
}

int is_a_real_maze(solver_t *solver)
{
    int i = 0;

    solver->len_y = my_strlen_array(solver->maze) - 1;
    solver->len_x = my_strlen(solver->maze[0]);
    if (solver->len_x < 2 || solver->len_y < 1)
        return 84;
    for (; i != solver->len_y + 1
    && my_strlen(solver->maze[i]) == solver->len_x;
    i++);
    if (i != solver->len_y + 1)
        return (84);
    if (check_symbol_and_initialisation(solver) == 84)
        return (84);
    return (0);
}