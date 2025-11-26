#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * print_char - call the function to print either
 * a character or a special format specifier
 *
 * @t: format specifier
 * @c: character to be displayed (or NULL-byte)
 * @buf: pointer of the buffer
 * @len_buf: current length of the buffer
 *
 * Return: size of the string (NULL byte excluded)
 */
int print_char(char t, char c, char *buf, int *len_buf)
{
	if (t == '\0')
		exit(1);
	else if (t == 'c')
	{
		add_buf(c, buf, len_buf);
		return (1);
	}
	else if (t == 'n')
		return (0);
	else if (t == '%' || t == 'l' || t == 'h')
	{
		add_buf('%', buf, len_buf);
		return (1);
	}
	else
	{
		add_buf('%', buf, len_buf);
		add_buf(t, buf, len_buf + 1);
		return (2);
	}
}


