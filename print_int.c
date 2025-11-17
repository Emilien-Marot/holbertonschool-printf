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
int _print_p(unsigned long int num)
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
		res = _print_p(d) + 1;
	else
	{
		_putchar('0');
		_putchar('x');
		res = 3;
	}
	_putchar(hex[u]);
	return (res);
}

/**
 * _print_x - prints an integer as an hexadecimal
 *
 * @num: integer to be printed
 *
 * Return: number of hex digits in the number
 */
int _print_x(unsigned int num)
{
	int hex[] = {
		'0', '1', '2', '3',
		'4', '5', '6', '7',
		'8', '9', 'a', 'b',
		'c', 'd', 'e', 'f'};
	int u, d, res;

	u = num % 16;
	d = num / 16;
	if (d >= 1)
		res = _print_x(d) + 1;
	else
		res = 1;
	_putchar(hex[u]);
	return (res);
}

/**
 * _print_o - prints an integer as an octal
 *
 * @num: integer to be printed
 *
 * Return: number of octal digits in the number
 */
int _print_o(unsigned int num)
{
	int u, d, res;

	u = num % 8;
	d = num / 8;
	if (d >= 1)
		res = _print_o(d) + 1;
	else
		res = 1;
	_putchar('0' + u);
	return (res);
}

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
