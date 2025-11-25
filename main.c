#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;
	int i;
	char str[1024];

	for (i = 0; i < 1023; i++)
		str[i] = 'a';
	str[1023] = '\0';

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	len = _printf("Length:[%d, %i]\n", len, len);
	len2 = printf("Length:[%d, %i]\n", len2, len2);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("Negative:[%d]\n", -762534);
	len2 = printf("Negative:[%d]\n", -762534);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("Unsigned:[%u]\n", ui);
	len2 = printf("Unsigned:[%u]\n", ui);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("Unsigned octal:[%o]\n", ui);
	len2 = printf("Unsigned octal:[%o]\n", ui);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	len2 = printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("Character:[%c]\n", 'H');
	len2 = printf("Character:[%c]\n", 'H');
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("String:[%s]\n", "I am a string !");
	len2 = printf("String:[%s]\n", "I am a string !");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("Address:[%p]\n", addr);
	len2 = printf("Address:[%p]\n", addr);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("Unknown:[%y]\n");
	len2 = printf("Unknown:[%y]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("%b\n", 98);
	len2 = printf("%b\n", 98);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("%x%X\n", -1024, -1024);
	len2 = printf("%x%X\n", -1024, -1024);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("%s\n", str);
	len2 = printf("%s\n", str);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("%S\n", "Best\nSchool");
	len2 = printf("%S\n", "Best\nSchool");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("%p\n", NULL);
	len2 = printf("%p\n", NULL);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("%r\n", "test reverse");
	len2 = _printf("%s\n", "test reverse");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("%R\n", "Why did the chicken cross the road?");
	len2 = _printf("%s\n", "Jul qvq gur puvpxra pebff gur ebnq?");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("%ld + %ld = %ld\n", LONG_MAX, LONG_MIN, (LONG_MAX + LONG_MIN));
	len2 = _printf("%ld + %ld = %ld\n", LONG_MAX, LONG_MIN, (LONG_MAX + LONG_MIN));
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("%li + %li = %li\n", LONG_MAX, LONG_MIN, (LONG_MAX + LONG_MIN));
	len2 = _printf("%li + %li = %li\n", LONG_MAX, LONG_MIN, (LONG_MAX + LONG_MIN));
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("%lu - %lu = %lu\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	len2 = _printf("%lu - %lu = %lu\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("%lo - %lo = %lo\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	len2 = _printf("%lo - %lo = %lo\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("%lx - %lx = %lx\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	len2 = _printf("%lx - %lx = %lx\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("%lX - %lX = %lX\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	len2 = _printf("%lX - %lX = %lX\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("%l %h\n");
	len2 = _printf("%l %h\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	return (0);
}
