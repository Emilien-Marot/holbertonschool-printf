#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _print_var - calls a function to print the variable
 *
 * @t: defines the type of value to print
 * @args: pointer to the list of value to print
 *
 * Description: function to print the variable
 * and return the size of the string to print
 *
 * Return: size of the string printed
 */
int _print_var(char t, va_list *args, char *buf, int *len_buf)
{
	if (t == '\0')
		exit(1);
	else if (t == '%')
	{
		add_buf('%', &buf[0], len_buf);
		return (1);
	}
	else if (t == 'p')
	{
		void *ptr = va_arg(*args, void *);

		return (_print_p((unsigned long int)ptr, &buf[0], len_buf));
	}
	else if (t == 'x' || t == 'X')
		return (_print_x(va_arg(*args, unsigned int), t, &buf[0], len_buf));
	else if (t == 'b')
		return (_print_b(va_arg(*args, unsigned int), &buf[0], len_buf));
	else if (t == 'o')
		return (_print_o(va_arg(*args, unsigned int), &buf[0], len_buf));
	else if (t == 'u')
		return (_print_u(va_arg(*args, unsigned int), &buf[0], len_buf));
	else if (t == 'd' || t == 'i')
		return (_print_i(va_arg(*args, int), &buf[0], len_buf));
	else if (t == 'c')
	{
		add_buf(va_arg(*args, int), &buf[0], len_buf);
		return (1);
	}
	else if (t == 's')
		return (_print_s(va_arg(*args, char*), &buf[0], len_buf));
	else if (t == 'n')
		return (0);
	add_buf('%', &buf[0], len_buf);
	add_buf(t, &buf[0], len_buf);
	return (2);
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
	int i, len_buf = 0, str_len = 0;
	char buf[1024];
	buf[0] = '\0';

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				exit(1);
			else
				str_len += _print_var(format[i], &args, buf, &len_buf);
		}
		else
		{
			add_buf(format[i], buf, &len_buf);
			str_len++;
		}
	}
	print_buf(buf, &len_buf);
	va_end(args);
	return (str_len);
}
