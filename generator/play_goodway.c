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

void case_badway(goodway_t *goodway, int random)
{
    goodway->random_potential_way = binare_tab(0,
    my_strlen_array(goodway->goodway_x) - 1,
    ((my_strlen_array(goodway->goodway_x) - 1) * 3));
    if (((my_strlen_array(goodway->goodway_x) - 1) * 2) != 0)
        random = random_value(0, my_strlen_array(goodway->goodway_x)
        - 1, ((my_strlen_array(goodway->goodway_x) - 1) * 2),
        goodway->random_potential_way);
    brick_wall(random, goodway);
    free_while_goodway(goodway);
    redefine_struct_goodway(goodway);
}