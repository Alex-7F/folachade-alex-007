/*
** EPITECH PROJECT, 2024
** fhgjk
** File description:
** ghgjkl
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
#include <errno.h>
#include <fcntl.h>
int count_fort(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '/') {
            return 1;
        }
    }
    return 0;
}

char *stray(char *src, char *rcs)
{
    int b = my_strlen(src);
    int c = my_strlen(rcs);
    char *rec = malloc(sizeof(char) * (b + c + 1));
    int r = 0;
    int x = 0;

    for (r = 0; src[r] != '\0'; r++) {
        rec[r] = src[r];
    }
    for (x = 0; rcs[x] != '\0'; x++) {
        rec[r] = rcs[x];
        r++;
    }
    return rec;
}

char *pro_mpt(void)
{
    ssize_t nread;
    size_t i = 0;
    char *str = NULL;

    mini_printf("$> ");
    nread = getline(&str, &i, stdin);
    if (nread == -1) {
        exit(0);
    }
    str[nread - 1] = '\0';
    return str;
}

int cond_one(char **tab, char *mac, char **ore)
{
    int m = 0;
    char **exe = array_doble(ore);

    if (tab[0][0] == '.' && tab[0][1] == '/') {
        cond_two(tab, ore);
    } else {
        cond_three(tab, mac, ore);
    }
    if (my_strcmp(tab[0], "env") == 0) {
        for (m = 0; exe[m] != NULL; m++) {
            mini_printf("%s\n", exe[m]);
        }
    }
    return 0;
}

int execu_te(char **tab, char *mac, char **ore)
{
    int status = 0;
    pid_t pid = fork();

    if (pid == 0) {
        cond_one(tab, mac, ore);
        exit(0);
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) != true) {
            mini_printf("%s\n", strsignal(WTERMSIG(status)));
            return 1;
        }
    }
    return 0;
}
