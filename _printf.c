#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	int i, str_len;

	va_start(format, args);
	
	write(1, &c, 1);
	va_end(args);
}
