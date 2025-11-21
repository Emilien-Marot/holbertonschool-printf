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
int _print_var(char t, int m, va_list *args, char *buf, int *len_buf)
{
	int res;
	long int i;
	long unsigned int u;

	res = 1;
	if (t == '\0')
		exit(1);
	else if (t == '%')
		add_buf('%', buf, len_buf);
	else if (t == 'p')
	{
		void *ptr = va_arg(*args, void *);

		if (ptr == NULL)
			res = _print_s("(nil)", buf, len_buf);
		else
			res = _print_p((unsigned long int)ptr, buf, len_buf);
	}
	else if (t == 's' || t == 'S' || t == 'R' || t == 'r')
		res = print_str(t, va_arg(*args, char*), buf, len_buf);
	else if (t == 'n')
		res = 0;
	else if (t == 'd' || t == 'i')
	{
		if (m == 0)
			i = va_arg(*args, int);
		else if (m < 0)
			i = (short int)va_arg(*args, int);
		else
			i = va_arg(*args, long int);
		res = _print_i((long int)i, buf, len_buf);
	}
	else if (t == 'c')
		add_buf(va_arg(*args, int), buf, len_buf);
	else if (t == 'x' || t == 'X' || t == 'b' || t == 'o' || t == 'u')
	{
		if (m == 0)
			u = va_arg(*args, unsigned int);
		else if (m < 0)
			u = (unsigned short int)va_arg(*args, int);
		else
			u = va_arg(*args, unsigned long int);
		res = _print_base((unsigned long int)u, t, buf, len_buf);
	}
	else
	{
		add_buf('%', buf, len_buf);
		add_buf(t, buf, len_buf);
		res = 2;
	}
	return (res);
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
	int m;

	if (buf == NULL)
		exit(-1);
	buf[0] = '\0';
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			m = '\0';
			if (format[i] == '\0')
				exit(1);
			
			while (format[i] == 'l' || format[i] == 'h')
			{
				if(format[i] == 'l')
					m += 1;
				else
					m -= 1;
				i++;
			}
			str_len += _print_var(format[i], m, &args, buf, &len_buf);
		}
		else
		{
			add_buf(format[i], buf, &len_buf);
			str_len++;
		}
	}
	print_buf(buf, &len_buf);
	va_end(args);
	free(buf);
	return (str_len);
}
