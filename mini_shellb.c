/*
** EPITECH PROJECT, 2024
** hjk
** File description:
** hkj
*/
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

int cond_two(char **tab, char **ore)
{
    if (access(tab[0], X_OK) == 0) {
        if (chdir(tab[0]) == 0) {
            mini_printf("%s: Permission denied.\n", tab[0]);
        } else {
            execve(tab[0], tab, ore);
        }
        if (errno == ENOEXEC) {
            mini_printf("%s: Exec format error.", tab[0]);
            mini_printf(" Wrong Architecture.\n");
        }
    } else {
        if (errno == EACCES) {
            mini_printf("%s: Permission denied.\n", tab[0]);
        }
        if (errno == ENOENT) {
            mini_printf("%s: Command not found.\n", tab[0]);
        }
    }
    return 0;
}

int cond_three(char **tab, char *mac, char **ore)
{
    if (access(mac, X_OK) == 0) {
        if (chdir(tab[0]) == 0) {
            mini_printf("%s: Command not found.\n", tab[0]);
        } else {
            execve(mac, tab, ore);
        }
        if (errno == ENOENT)
            mini_printf("%s: Command not found.\n", tab[0]);
    } else {
        mini_printf("%s: Command not found.\n", mac);
    }
    return 0;
}

void condi_tion(char **tab)
{
    if (my_strcmp(tab[0], "exit") == 0) {
        mini_printf("%s\n", "exit");
        exit(0);
    }
}

char *myfun_ct(char **env, char *src)
{
    char **count = array(env);
    char coun[] = "/";
    char *mac = NULL;
    char *str = NULL;

    for (int m = 1; count[m] != NULL; m++) {
        mac = stray(count[m], coun);
        str = stray(mac, src);
        if (access(str, X_OK) == 0) {
            return str;
        }
    }
    return src;
}

static int t_func(char **tab)
{
    int fd = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], ">") == 0 && tab[i + 1] != NULL) {
            fd = open(tab[i + 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
            dup2(fd, STDOUT_FILENO);
            close(fd);
            tab[i] = NULL;
        }
    }
}

static int m_func(char **tab)
{
    int fd = 0;

    for (int m = 0; tab[m] != NULL; m++) {
        if (my_strcmp(tab[m], ">>") == 0 && tab[m + 1] != NULL) {
            fd = open(tab[m + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
            dup2(fd, STDOUT_FILENO);
            close(fd);
            tab[m] = NULL;
        }
    }
}

static int mf_unc(char **tab)
{
    int fd = 0;

    for (int m = 0; tab[m] != NULL; m++) {
        if (my_strcmp(tab[m], "<") == 0 && tab[m + 1] != NULL) {
            fd = open(tab[m + 1], O_RDONLY);
            dup2(fd, STDIN_FILENO);
            close(fd);
            tab[m] = NULL;
        }
    }
}

static int my_func(char **env, char **tab)
{
    int line;
    int fd = 0;
    char *mac = NULL;
    int saved_stdout = dup(STDOUT_FILENO);
    int e = dup(STDIN_FILENO);

    condi_tion(tab);
    if (strin_gue(env, tab) == 0) {
    } else {
        mac = myfun_ct(env, tab[0]);
        t_func(tab);
        m_func(tab);
        mf_unc(tab);
        execu_te(tab, mac, env);
    }
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);
    dup2(e, STDIN_FILENO);
    close(e);
    return 0;
}

static int ess_aie(char **env, char *e)
{
    char **tab = NULL;

    if (my_stlen(e) == 0) {
    } else {
        tab = my_str_to_word_array(e, ' ', '\t');
        my_func(env, tab);
    }
    return 0;
}

int my_funct(char **env)
{
    char *str = NULL;
    char **l = NULL;
    char **src;
    int i;

    while (1) {
        str = pro_mpt();
        if (my_stlen(str) == 0) {
            free(str);
            continue;
        }
        i = 0;
        l = my_str_to_word_array(str, ';', ';');
        while (l[i] != NULL) {
            ess_aie(env, l[i]);
            i++;
        }
    }
}
