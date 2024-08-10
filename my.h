/*
** EPITECH PROJECT, 2024
** prototypes
** File description:
** functions prototypes
*/
#include <stdarg.h>
#ifndef __MY_H__
    #define __MY_H__

    #include <stdarg.h>
char *my_strcat(char *dest, char *src);
int my_strlen(char const *str);
int my_strcmp(char *s1, char *s2);
int count_line(char *str, char d, char c);
char **my_str_to_word_array(char *str, char d, char c);
int count_fort(char *str);
char *stray(char *src, char *rcs);
char *pro_mpt(void);
int cond_one(char **tab, char *mac, char **ore);
int execu_te(char **tab, char *mac, char **ore);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int v_mini_printf(va_list args, const char *format, int a);
int mini_printf(const char *format, ...);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char *src);
char **array_doble(char **atr);
int my_stlen(char const *str);
int cond_two(char **tab, char **ore);
int cond_three(char **tab, char *mac, char **ore);
void condi_tion(char **tab);
int my_funct(char **env);
char **array(char **atr);
char *myfun_ct(char **env, char *src);
int my_strncmp(char *s1, char *s2, int n);
int strin_gue(char **env, char **src);
void free_item(char **item);
char *my_strcpy(char *dest, char const *src);
int str_int(char **env, char **src, char *one, char *two);
static int my_func(char **env, char **tab);
static int ess_aie(char **env, char *e);

#endif
