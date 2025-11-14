#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * _print_var - calls a function to print the variable
 *
 * @str: string to be displayed
 *
 * Description: function to print the variable and return the size of the string to print
 *
 * Return: size of the string printed
 */
int _print_var(char t, va_list *args)
{
        if (t == '\0')
                exit(1);
        else if (t == '%')
        {
                _putchar('%');
                return (1);
        }
        else if (t == 'p')
                return (_print_p(va_arg(*args, long unsigned int)));
        else if (t == 'x' || t == 'X')
                return (_print_x(va_arg(*args, unsigned int)));
        else if (t == 'o')
                return (_print_o(va_arg(*args, unsigned int)));
        else if (t == 'u')
                return (_print_u(va_arg(*args, unsigned int)));
        else if (t == 'd' || t == 'i')
                return (_print_i(va_arg(*args, int)));
        else if (t == 'c')
        {
                _putchar(va_arg(*args, int));
                return (1);
        }
        else if (t == 's')
                return (_print_s(va_arg(*args, char*)));
        else if (t == 'n')
                return (0);
        else
        {
                _putchar('%');
                _putchar(t);
                return (2);
        }
}

/**
 * _printf - prints a string
 *
 * @format: string to be printed
 * @...: data to insert in format in place of the format modifier
 *
 * Description: function to print a string,
 * inserting data in place of the format modifier
 * Return: length of the final string
 */
int _printf(const char *format, ...)
{
        va_list args;
        int i, str_len;

        va_start(args, format);

        for (i = 0; format[i] != '\0'; i++)
        {
                if (format[i] == '%')
                {
                        i++;
                        if (format[i] == '\0')
                                exit(1);
                        else
                                str_len += _print_var(format[i], &args);
                }
                else
                {
                        _putchar(format[i]);
                        str_len++;
                }
        }
        va_end(args);
        return (str_len);
}
