#include <stdio.h>
#include <unistd.h>

/**
 * print_buf - writes the buffer to stdout
 *
 * @buf: pointer of the buffer
 * @len_buf: current length of the buffer
 *
 * Return: On success 1.
 * If the buffer is empty 0
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_buf(char *buf, int *len_buf)
{
	if (*len_buf == 0)
		return (0);
	return (write(1, buf, *len_buf));
	*len_buf = 0;
}

/**
 * add_buf - append the character c to the buffer
 *
 * @c: The character to print
 * @buf: pointer of the buffer
 * @len_buf: current length of the buffer
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int add_buf(char c, char *buf, int *len_buf)
{
	*(buf + *len_buf) = c;
	*len_buf = *len_buf + 1;
	*(buf + *len_buf) = '\0';
	if (*len_buf >= 1024)
		return (print_buf(buf, len_buf));
	return (1);
}
