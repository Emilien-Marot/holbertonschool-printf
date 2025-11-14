#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * _print_s - prints a string
 *
 * @str: string to be displayed
 *
 * Return: size of the string (NULL byte excluded)
 */
int _print_p(long unsigned int num)
{
        int hex[] = {'0','1','2','3','4','5','6','7','8','9','a','b','f','d','e','f'};
        int u, d, res;

        u = num % 16;
        d = num / 16;
        if (d >= 1)
                res = _print_p(d) + 1;
        else
        {
                _putchar('0');
                _putchar('x');
                res = 3;
        }
        _putchar(hex[u]);
        return(res);
}

/**
 * _print_s - prints a string
 *
 * @str: string to be displayed
 *
 * Return: size of the string (NULL byte excluded)
 */
int _print_x(unsigned int num)
{
        int hex[] = {'0','1','2','3','4','5','6','7','8','9','a','b','f','d','e','f'};
        int u, d, res;

        u = num % 16;
        d = num / 16;
        if (d >= 1)
                res = _print_x(d) + 1;
        else
                res = 1;
        _putchar(hex[u]);
        return(res);
}

/**
 * _print_s - prints a string
 *
 * @str: string to be displayed
 *
 * Return: size of the string (NULL byte excluded)
 */
int _print_o(unsigned int num)
{
        int u, d, res;

        u = num % 8;
        d = num / 8;
        if (d >= 1)
                res = _print_o(d) + 1;
        else
                res = 1;
        _putchar('0' + u);
        return(res);
}

/**
 * _print_s - prints a string
 *
 * @str: string to be displayed
 *
 * Return: size of the string (NULL byte excluded)
 */
int _print_u(unsigned int num)
{
        int u, d, res;

        u = num % 10;
        d = num / 10;
        if (d >= 1)
                res = _print_i(d) + 1;
        else
                res = 1;
        _putchar('0' + u);
        return(res);
}

/**
 * _print_s - prints a string
 *
 * @str: string to be displayed
 *
 * Return: size of the string (NULL byte excluded)
 */
int _print_i(int num)
{
        int u, d, res;

        u = num % 10;
        d = num / 10;
        if (num < 0)
        {
                _putchar('-');
                d = -1 * d;
                u = -1 * u;
        }
        if (d >= 1)
                res = _print_i(d) + 1;
        else
                res = 1;
        _putchar('0' + u);
        return(res);
}
