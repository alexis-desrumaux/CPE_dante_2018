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

void free_cursor(cursor_t **cursor)
{
    for (int i = 0; cursor[i] != NULL; i++) {
        free(cursor[i]);
    }
    free(cursor);
}