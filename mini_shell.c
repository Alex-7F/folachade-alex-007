/*
** EPITECH PROJECT, 2024
** sdfghjkil*
** File description:
** rfgtyu
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (dest[i] != '\0') {
        i++;
    }
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}

int my_strlen(char const *str)
{
    int t = 0;

    while (str[t] != '\0') {
        t++;
    }
    return t;
}

int count_line(char *str, char d, char c)
{
    int t = 0;
    int e = 0;
    int i = 0;

    for (t = 0; str[t] != '\0' && t < my_strlen(str); t++) {
        if (str[t] != '\0' && str[t] != c && str[t] != d) {
            i++;
        }
        for (; str[t] != '\0' && str[t] != c && str[t] != d; t++);
    }
    return i;
}

char **my_str_to_word_array(char *str, char d, char c)
{
    int i = 0;
    int j;
    int x = 0;
    int y = 0;
    int line = count_line(str, d, c);
    char **array = malloc(sizeof(char *) * (line));

    for (y = 0; y < line; y++) {
        for (; str[i] != '\0' && str[i] == c || str[i] == d; i++);
        x = i;
        for (; str[i] != '\0' && str[i] != c && str[i] != d; i++);
        array[y] = malloc(sizeof(char) * (i - x + 1));
        for (j = 0; x < i; x++) {
            array[y][j] = str[x];
            j++;
        }
        array[y][j] = '\0';
    }
    array[y] = NULL;
    return array;
}

int main(int argc, char **argv, char **env)
{
    char *str = NULL;
    char count[] = "/bin/";
    char *mac = NULL;
    int line = 0;
    char **tab = NULL;

    if (argc != 1) {
        return 84;
    }
    my_funct(env);
    return 0;
}
