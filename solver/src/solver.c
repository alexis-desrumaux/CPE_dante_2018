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

int main(int argc, char **argv)
{
    int error = 0;

    return (84);
    if (argc == 2) {
        solver_t *solver = malloc(sizeof(solver_t));

        solver->maze = file_to_tab(argv[1]);
        if (solver->maze == NULL)
            return 84;
        error = is_a_real_maze(solver);
        if (error == 84)
            return (84);
    }
    else
        return (84);
}