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
 * @t: character for the format to define the case (lower or upper)
 *
 * Return: number of hex digits in the number
 */
int _print_x(unsigned int num, char t)
{
	char x;
	int hex[] = {
		'0', '1', '2', '3',
		'4', '5', '6', '7',
		'8', '9', 'a', 'b',
		'c', 'd', 'e', 'f'};
	int u, d, res;

	u = num % 16;
	d = num / 16;
	if (d >= 1)
		res = _print_x(d, t) + 1;
	else
		res = 1;
	x = hex[u];
	if (x >= 'a' && x <= 'f' && t == 'X')
		x = x + 'A' - 'a';
	_putchar(x);
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
 * _print_b - prints an integer as a binary number
 *
 * @num: integer to be printed
 *
 * Return: number of bits in the number
 */
int _print_b(unsigned int num)
{
	int u, d, res;

	u = num % 2;
	d = num / 2;
	if (d >= 1)
		res = _print_b(d) + 1;
	else
		res = 1;
	_putchar('0' + u);
	return (res);
}
