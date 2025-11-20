#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * _print_p - prints the address of a pointer
 *
 * @num: address of the pointer
 *
 * Return: number of hex digits in the pointer's address
 */
int _print_p(unsigned long int num, char *buf, int *len_buf)
{
	int hex[] = {
		'0', '1', '2', '3',
		'4', '5', '6', '7',
		'8', '9', 'a', 'b',
		'c', 'd', 'e', 'f'};
	unsigned long int u, d;
	int res;

	u = num % 16;
	d = num / 16;
	if (d >= 1)
		res = _print_p(d, buf, len_buf) + 1;
	else
	{
		add_buf('0', buf, len_buf);
		add_buf('x', buf, len_buf);
		res = 3;
	}
	add_buf(hex[u], buf, len_buf);
	return (res);
}

/**
 * _print_x - prints an integer as an hexadecimal
 *
 * @num: integer to be printed
 * @t: character for the format to define the case (lower or upper)
 *
 * Return: number of hex digits in the number
 */
int _print_base(unsigned int num, char t, char *buf, int *len_buf)
{
	char x;
	int hex[] = {
		'0', '1', '2', '3',
		'4', '5', '6', '7',
		'8', '9', 'a', 'b',
		'c', 'd', 'e', 'f'};
	int u, d, res, base;

	if (t == 'x' || t == 'X')
		base = 16;
	else if (t == 'u' || t == 'u')
		base = 10;
	else if (t == 'o')
		base = 8;
	else if (t == 'b')
        	base = 2;
	u = num % base;
	d = num / base;
	if (d >= 1)
		res = _print_base(d, t, buf, len_buf) + 1;
	else
		res = 1;
	x = hex[u];
	if (x >= 'a' && x <= 'f' && t == 'X')
		x = x + 'A' - 'a';
	add_buf(x, buf, len_buf);
	return (res);
}
