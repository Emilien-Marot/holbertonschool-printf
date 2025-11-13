#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * _print_s - prints a string
 *
 * @str: string to be displayed
 *
 * Return: size of the string (NULL byte excluded)
 */
int _print_s(char *str)
{
	int i, len = 0;
	char *s;

	if (str != NULL)
		s = str;
	else
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
		len++;
	}
	return (len);
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
			if (format[i] == '%')
			{
				_putchar('%');
				str_len++;
			}
			else if (format[i] == 'c')
			{
				_putchar(va_arg(args, int));
				str_len++;
			}
			else if (format[i] == 's')
			{
				str_len += _print_s(va_arg(args, char*));
			}
			else
			{
				_putchar('%');
				_putchar(format[i]);
				str_len += 2;
			}
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
