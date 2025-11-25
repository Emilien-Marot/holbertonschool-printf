#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * format_i - gives the int from the list in the right format
 *
 * @args: pointer to the list of value to print
 * @m: integer representing the size modifier
 *
 * Description: function to get the value from the list,
 * convert it to the right format then to long int
 *
 * Return: the integer with the right number of byte
 */
long int format_i(va_list *args, int m)
{
	long int i;

	if (m == 0)
		i = va_arg(*args, int);
	else if (m < 0)
		i = (short int)va_arg(*args, int);
	else
		i = va_arg(*args, long int);
	return ((long int)i);
}

/**
 * format_u - gives the unsigned int from the list in the right format
 *
 * @args: pointer to the list of value to print
 * @m: integer representing the size modifier
 *
 * Description: function to get the value from the list,
 * convert it to the right format then to unsigned long int
 *
 * Return: the unsigned integer with the right number of byte
 */
long int format_u(va_list *args, int m)
{
	unsigned long int u;

	if (m == 0)
		u = va_arg(*args, unsigned int);
	else if (m < 0)
		u = (unsigned short int)va_arg(*args, int);
	else
		u = va_arg(*args, unsigned long int);
	return ((unsigned long int)u);
}

/**
 * _print_var - calls a function to print the variable
 *
 * @t: defines the type of value to print
 * @m: integer representing the size modifier
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
	char c = '\0';

	if (t == '\0')
		exit(1);
	else if (t == 'p')
	{
		void *ptr = va_arg(*args, void *);

		if (ptr == NULL)
			return (_print_s("(nil)", buf, len_buf));
		else
			return (_print_p((unsigned long int)ptr, buf, len_buf));
	}
	else if (t == 's' || t == 'S' || t == 'R' || t == 'r')
		return (print_str(t, va_arg(*args, char*), buf, len_buf));
	else if (t == 'd' || t == 'i')
		return (_print_i(format_i(args, m), buf, len_buf));
	else if (t == 'x' || t == 'X' || t == 'b' || t == 'o' || t == 'u')
		return (_print_base(format_u(args, m), t, buf, len_buf));
	else
		return (print_char(t, c, buf, len_buf));
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
				if (format[i] == 'l')
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
