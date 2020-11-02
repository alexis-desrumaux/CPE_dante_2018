/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** main_tools
*/

#include "mylib.h"

void free_maze_struct(maze_t *maze)
{
    free_strtab(maze->maze);
    free(maze);
}

int isnumber(char *str)
{
    int i = 0;
    int nb = 0;
    int len_str = my_strlen(str);

    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57)
            nb++;
        i++;
    }
    if (len_str == nb)
        return (1);
    else if (len_str != nb)
        return (0);
    return (0);
}

int *binare_tab_spec(int *random, int max)
{
    int *alea = malloc(sizeof(int) * max);
    int j = 0;
    int i = 0;

    while (i != max) {
        alea[i] = random[j];
        i++;
        if (random[j + 1] != NULL)
            j++;
        else
            j = 0;
    }
    return alea;
}

int *binare_tab(int lower, int upper, int max)
{
    int nb = lower;
    int j = 0;
    int *alea = malloc(sizeof(int) * max);

    while (j != max) {
        if (nb == upper + 1)
            nb = lower;
        alea[j] = nb;
        nb++;
        j++;
    }
    return (alea);
}

void reset_stuck(maze_t *maze, cursor_t *c)
{
    c->stuck = 0;
    c->stuck_left = 0;
    c->stuck_right = 0;
    c->stuck_up = 0;
    c->stuck_down = 0;
}