/*
** EPITECH PROJECT, 2019
** include.h
** File description:
** include.h
*/

#ifndef INCLUDE_H_
    #define INCLUDE_H_

#include "struct.h"

char *get_next_line(int fd);
void goodway_maze(maze_t *maze);
int *binare_tab(int lower, int upper, int max);
int *binare_tab_spec(int *random, int max);
int random_value(int lower, int upper, int max, int *alea);
int goodway_stuck(goodway_t *goodway);
int random_value(int lower, int upper, int max, int *alea);
void anti_cheat_2(maze_t *maze);
void anti_cheat(maze_t *maze);
void maze_stuck_dir2(maze_t *maze, cursor_t *c);
void maze_stuck_dir(maze_t *maze, cursor_t *c);
int cut_pos_maze(maze_t *maze, cursor_t *c);
void case_stuck(maze_t *maze, cursor_t *c);
void choose_dir(maze_t *maze, cursor_t *c, int random);
void def_value_build_walls(maze_t *maze);
void build_walls(maze_t *maze);
int my_stuck_four(goodway_t *good, char **pos, int i, int len_array);
int case_stuck_goodway(goodway_t *good, int stuck);
void check_x(goodway_t *good, int random);
void check_y(goodway_t *good, int random);
void connect_room(goodway_t *goodway);
int count_badway(char **maze);
int count_goodway(goodway_t *goodway);
void print_goodway(char **goodway);
int is_stuck_dir(goodway_t *goodway, int xdir, int ydir);
void add_pos_goodway(goodway_t *goodway);
int goodway_stuck(goodway_t *goodway);
void redefine_struct_goodway(goodway_t *goodway);
void free_while_goodway(goodway_t *goodway);
void play_goodway_maze(goodway_t *goodway, maze_t *maze, int random);
void goodway_maze(maze_t *maze);
void free_maze_struct(maze_t *maze);
int isnumber(char *str);
int *binare_tab(int lower, int upper, int max);
void reset_stuck(maze_t *maze, cursor_t *c);
void full_wall(int argc, char **argv, maze_t *maze);
void init(maze_t *maze, char **argv);
int main(int argc, char **argv);
int maze_stuck(maze_t *maze, cursor_t *cursor);
int down_management(maze_t *maze, cursor_t *c);
int right_management(maze_t *maze, cursor_t *c);
int up_management(maze_t *maze, cursor_t *c);
int left_management(maze_t *maze, cursor_t *c);
void free_goodway_struct(goodway_t *goodway);
char **cp_strtab(char **origin, int malloc_v);
void delete_all_a_symbol(char **maze);
void brick_wall(int random, goodway_t *goodway);
void potential_way_count(goodway_t *good, int y, int x);
void free_cursor(cursor_t **cursor);
int cursor_move(maze_t *maze, int random);
int cursor_stop(maze_t *maze, int stop);
int begin_generator(maze_t *maze, int argc, char **argv);
void create_cursor_struct(maze_t *maze);
cursor_t *cursor_gen(int i, int col, int rowmax, int colmax);
void case_badway(goodway_t *goodway, int random);

#endif /* !INCLUDE_H_ */
