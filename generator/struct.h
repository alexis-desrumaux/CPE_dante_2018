/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_


typedef struct cursor_s
{
    int x;
    int y;
    char **pos;
    int *alea;
    int *good_value_tab;
    int gv_tab;
    int i_pos;
    int stuck_up;
    int stuck_down;
    int stuck_left;
    int stuck_right;
    int stuck;
    int stop;
    int free_stop;
} cursor_t;

typedef struct maze_s
{
    char **maze;
    int row;
    int col;
    int nbcursor;
    int perfect;
    cursor_t **cursor;
    cursor_t *cursor1;
    cursor_t *cursor2;
    cursor_t *cursor3;
} maze_t;

typedef struct goodway_s
{
    char **maze;
    char **pos;
    char **goodway_x;
    char **goodway_y;
    int *random_potential_way;
    int i_pos;
    int row;
    int col;
    int x;
    int y;
    int *alea;
} goodway_t;

#endif /* !STRUCT_H_ */
