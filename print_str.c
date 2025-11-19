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
