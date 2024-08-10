/*
** EPITECH PROJECT, 2024
** day printf
** File description:
** mini_printf
*/

#include "my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int b = 0;

    while (str[b] != '\0') {
        my_putchar(str[b]);
        b = b + 1;
    }
    return 0;
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + '0');
    }
    if (nb > 0 && nb < 9) {
        my_putchar(nb + '0');
    }
}

int v_mini_printf(va_list args, const char *format, int a)
{
    if (format[a] != '%') {
    my_putchar(format[a]);
    }
    if (format[a] == '%' && (format[a + 1] == 'd' || format[a + 1] == 'i')) {
        my_put_nbr(va_arg(args, int));
        a++;
    }
    if (format[a] == '%' && format[a + 1] == 's') {
        my_putstr(va_arg(args, char *));
        a++;
    }
    if (format[a] == '%' && format[a + 1] == 'c') {
        my_putchar(va_arg(args, int));
        a++;
    }
    if (format[a] == '%' && format[a + 1] == '%') {
        my_putchar('%');
        a++;
    }
    return a;
}

int mini_printf(const char *format, ...)
{
    va_list args;
    int a = 0;

    va_start(args, format);
    for (a = 0; format[a] != '\0'; a++) {
        a = v_mini_printf(args, format, a);
    }
    va_end(args);
    return 0;
}
