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
 * @buf: pointer of the buffer
 * @len_buf: current length of the buffer
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
		add_buf('%', buf, len_buf);
		return (1);
	}
	else if (t == 'p')
	{
		void *ptr = va_arg(*args, void *);

		return (_print_p((unsigned long int)ptr, buf, len_buf));
	}
	else if (t == 's')
		return (_print_s(va_arg(*args, char*), buf, len_buf));
	else if (t == 'n')
		return (0);
	else if (t == 'd' || t == 'i')
		return (_print_i(va_arg(*args, int), buf, len_buf));
	else if (t == 'c')
	{
		add_buf(va_arg(*args, int), buf, len_buf);
		return (1);
	}
	else if (t == 'x' || t == 'X' || t == 'b' || t == 'o' || t == 'u')
		return (_print_base(va_arg(*args, unsigned int), t, buf, len_buf));
	add_buf('%', buf, len_buf);
	add_buf(t, buf, len_buf);
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
	char *buf = malloc(1024 * sizeof(char));

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
