#include <stdio.h>
#include <unistd.h>

void print_buf(char *buf, int *len_buf)
{
	if (*len_buf == 0)
		return;
	write(1, buf, *len_buf);
	*len_buf = 0;
}

/**
 * add_buf - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void add_buf(char c, char *buf, int *len_buf)
{
	*(buf + *len_buf) = c;
	*len_buf = *len_buf + 1;
	*(buf + *len_buf) = '\0';
	if(*len_buf >= 1024)
		print_buf(buf, len_buf);
}
