/*
** EPITECH PROJECT, 2024
** tgfhjk
** File description:
** rtgrfhj
*/
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include <string.h>
#include <stdio.h>

int my_strncmp(char *s1, char *s2, int n)
{
    int k = 0;

    while (k < n) {
        if (s1[k] != s2[k])
            return -1;
        k++;
    }
    return 0;
}

char **array(char **atr)
{
    int i = 0;
    char **scr;
    int a = 0;

    for (a = 0; atr[a] != NULL; a++) {
        if (my_strncmp(atr[a], "PATH", 4) == 0) {
            scr = my_str_to_word_array(atr[a], '=', ':');
        }
    }
    return scr;
}
