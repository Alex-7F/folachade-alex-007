/*
** EPITECH PROJECT, 2024
** day08
** File description:
** a file strdup
*/

#include "my.h"
#include <stdlib.h>
#include <stddef.h>

char *my_strcpy(char *dest, char const *src)
{
    int a;

    for (a = 0; src[a] != '\0'; a++) {
        dest[a] = src[a];
    }
    dest[a] = '\0';
    return dest;
}

char *my_strdup(char *s)
{
    int l = my_strlen(s) + 1;
    char *c = malloc(l);

    if (c == NULL) {
        return NULL;
    }
    my_strcpy(c, s);
    return c;
}

char **array_doble(char **atr)
{
    int i = 0;
    char **scr;
    int a = 0;

    while (atr[i] != NULL) {
        i++;
    }
    scr = malloc(sizeof(char *) * i);
    for (a = 0; atr[a] != NULL; a++) {
        scr[a] = my_strdup(atr[a]);
    }
    scr[a] = NULL;
    return scr;
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    return (s1[i] - s2[i]);
}

int my_stlen(char const *str)
{
    int t = 0;
    int i = 0;

    while (str[t] != '\0') {
        if (str[t] != ' ' && str[t] != '\t') {
            i++;
        }
        t++;
    }
    return i;
}
