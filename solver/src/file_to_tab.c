/*
** EPITECH PROJECT, 2019
** ALEXIS DESRUMAUX
** File description:
** file.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "mylib.h"

char **file_to_tab_str(int *size, char *str, char **file)
{
    if (*size < 1)
        str[0] = '\0';
    if (*size > 1) {
        if (str[*size - 1] == '\n')
            str[*size - 1] = '\0';
        else
            str[*size] = '\0';
    }
    if (*size != -1) {
        to_strtab_char(file, str);
        file = re_malloc_strtab(file);
        if (!file)
            return NULL;
        free(str);
    }
    return file;
}

char **file_to_tab(char *path)
{
    FILE *fd = fopen(path, "r");
    int *size = malloc(sizeof(int));
    size_t bufsize = 0;
    char *str = NULL;
    char **file = define_strtab(sizeof(char *) * 5);

    *size = 0;
    if (!file || fd == NULL)
        return NULL;
    while (1) {
        *size = getline(&str, &bufsize, fd);
        file = file_to_tab_str(size, str, file);
        if (file[0] == NULL || file == NULL)
            return (NULL);
        if (*size == -1)
            break;
        bufsize = 0;
        *size = 0;
    }
    return file;
}