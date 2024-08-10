/*
** EPITECH PROJECT, 2024
** gfhjk
** File description:
** fdghjk
*/
#include "my.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

char *prev;
char **array_in(char **atr, char *c, int n)
{
    int i = 0;
    char **scr;
    int a = 0;

    for (a = 0; atr[a] != NULL; a++) {
        if (my_strncmp(atr[a], c, n) == 0) {
            scr = my_str_to_word_array(atr[a], '=', ':');
        }
    }
    return scr;
}

int cond_ition(char **src)
{
    if (errno == ENOTDIR) {
        mini_printf("%s: Not a directory.\n", src[1]);
        return 0;
    } else {
        mini_printf("%s: No such file or directory.\n", src[1]);
        return 0;
    }
}

int conditi_on(char **src)
{
    if (chdir(src[1]) == 0) {
        return 0;
    } else {
        cond_ition(src);
        return 0;
    }
}

int str_int(char **env, char **src, char *one, char *two)
{
    if (my_strcmp(src[0], "cd") == 0) {
        if (my_strcmp(src[1], "-") == 0) {
            two = my_strdup(getcwd(one, 1024));
            chdir(prev);
            prev = my_strdup(two);
            return 0;
        } else {
            prev = getcwd(one, 1024);
            conditi_on(src);
            return 0;
        }
    }
    return 1;
}

int strin_gue(char **env, char **src)
{
    char **str = NULL;
    char *one = NULL;
    char *two = NULL;

    if (my_strcmp(src[0], "cd") == 0 && (src[1] != NULL && src[2] != NULL)) {
        mini_printf("%s: Too many arguments.\n", src[0]);
        return 0;
    }
    if (my_strcmp(src[0], "cd") == 0 && (src[1] == NULL || src[1][0] == '~')) {
        str = array_in(env, "HOME", 4);
        prev = getcwd(one, 1024);
        chdir(str[1]);
        return 0;
    }
    if (str_int(env, src, one, two) == 0) {
        return 0;
    } else {
        return 1;
    }
    return 1;
}
