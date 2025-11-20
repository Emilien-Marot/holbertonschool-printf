#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * _print_i - prints an integer
 *
 * @num: integer to be printed
 * @buf: pointer of the buffer
 * @len_buf: current length of the buffer
 *
 * Return: number of digits in the number
 */
int _print_i(int num, char *buf, int *len_buf)
{
	int u, d, res = 0;

	u = num % 10;
	d = num / 10;
	if (num < 0)
	{
		add_buf('-', buf, len_buf);
		d = -1 * d;
		u = -1 * u;
		res = 1;
	}
	if (d >= 1)
		res += _print_i(d, buf, len_buf) + 1;
	else
		res += 1;
	add_buf(('0' + u), buf, len_buf);
	return (res);
}
