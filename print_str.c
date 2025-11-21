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
	int hex[] = {
		'0', '1', '2', '3',
		'4', '5', '6', '7',
		'8', '9', 'A', 'B',
		'C', 'D', 'E', 'F'};
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
			add_buf(hex[s[i] / 16], buf, len_buf);
			add_buf(hex[s[i] % 16], buf, len_buf);
			len += 4;
		}
	}
	return (len);
}

/**
 * _print_r - prints a reversed string
 *
 * @str: string to be reversed
 * @i: index of the character
 * @buf: pointer of the buffer
 * @len_buf: current length of the buffer
 *
 * Return: size of the string (NULL byte excluded)
 */
int _print_r(char *str, int i, char *buf, int *len_buf)
{
	int res;

	if (str == NULL)
		return (_print_s("(lin)", buf, len_buf));
	if (str[i] == '\0')
		return (0);
	res = 1 + _print_r(str, i + 1, buf, len_buf);
	add_buf(str[i], buf, len_buf);
	return (res);
}

/**
 * _print_r2 - prints a string after a ROT13
 *
 * @str: string to be displayed
 * @buf: pointer of the buffer
 * @len_buf: current length of the buffer
 *
 * Return: size of the string (NULL byte excluded)
 */
int _print_r2(char *str, char *buf, int *len_buf)
{
	int i, len = 0;

	if (str == NULL)
		return (_print_s("(ahyy)", buf, len_buf));
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			add_buf('a' + ((str[i] + 13 - 'a') % 26), buf, len_buf);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			add_buf('A' + ((str[i] + 13 - 'A') % 26), buf, len_buf);
		else
			add_buf(str[i], buf, len_buf);
		len++;
	}
	return (len);
}
