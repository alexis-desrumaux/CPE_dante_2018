/*
** EPITECH PROJECT, 2019
** Tek1
** File description:
** minishell
*/

#include "mylib.h"
#include <time.h>

void full_wall(int argc, char **argv, maze_t *maze)
{
    char *str = malloc(my_putint(argv[1]) * 2);
    int i = 0;

    maze->maze = define_strtab((my_putint(argv[2]) * my_putint(argv[1])) * 2);
    for (;i != my_putint(argv[1]); i++)
        str[i] = '*';
    str[i] = '\0';
    i = 0;
    for (; i != my_putint(argv[2]); i++)
        maze->maze = to_strtab_char(maze->maze, str);
    free(str);
    maze->maze[0][0] = 'O';
    maze->maze[maze->col - 1][maze->row - 1] = 'O';
    if (argc == 3)
        maze->perfect = 0;
    else if (argc == 4 && match_str(argv[3], "perfect") == 1)
        maze->perfect = 1;
    create_cursor_struct(maze);
    build_walls(maze);
}

void init(maze_t *maze, char **argv)
{
    maze->row = my_putint(argv[1]);
    maze->col = my_putint(argv[2]);
}

int main(int argc, char **argv)
{
    maze_t *maze = malloc(sizeof(maze_t));


    if (argc >= 3 && argc < 5 && maze != NULL) {
        return begin_generator(maze, argc, argv);
    } else {
        free (maze);
        return (84);
    }
    return (84);
}
