#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _print_s - prints a string
 *
 * @str: string to be displayed
 * @buf: pointer of the buffer
 * @len_buf: current length of the buffer
 *
 * Return: size of the string (NULL byte excluded)
 */
int _print_s(char *str, char *buf, int *len_buf)
{
	int i, len = 0;
	char *s;

	if (str != NULL)
		s = str;
	else
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		add_buf(s[i], buf, len_buf);
		len++;
	}
	return (len);
}

/**
 * _print_s2 - prints a string replacing non-printable characters
 *
 * @str: string to be displayed
 * @buf: pointer of the buffer
 * @len_buf: current length of the buffer
 *
 * Return: size of the string (NULL byte excluded)
 */
int _print_s2(char *str, char *buf, int *len_buf)
{
	int i, len = 0;
	char *s;

	if (str != NULL)
		s = str;
	else
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 32 && s[i] < 127)
		{
			add_buf(s[i], buf, len_buf);
			len++;
		}
		else
		{
			add_buf('\\', buf, len_buf);
			add_buf('x', buf, len_buf);
			if (s[i] < 16)
				add_buf('0', buf, len_buf);
			_print_base((int)s[i], 'x', buf, len_buf);
			len += 4;
		}
	}
	return (len);
}
