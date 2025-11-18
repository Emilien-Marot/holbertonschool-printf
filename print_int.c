#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * _print_u - prints an unsigned integer
 *
 * @num: integer to be printed
 *
 * Return: number of digits in the number
 */
int _print_u(unsigned int num)
{
	int u, d, res;

	u = num % 10;
	d = num / 10;
	if (d >= 1)
		res = _print_i(d) + 1;
	else
		res = 1;
	_putchar('0' + u);
	return (res);
}

/**
 * _print_i - prints an integer
 *
 * @num: integer to be printed
 *
 * Return: number of digits in the number
 */
int _print_i(int num)
{
	int u, d, res = 0;

	u = num % 10;
	d = num / 10;
	if (num < 0)
	{
		_putchar('-');
		d = -1 * d;
		u = -1 * u;
		res = 1;
	}
	if (d >= 1)
		res += _print_i(d) + 1;
	else
		res += 1;
	_putchar('0' + u);
	return (res);
}
