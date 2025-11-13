#include "main.h"
#include <stdarg.h>

int _print_s(const char *s)
{
	int i, len = 0;

	for(i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
		len++;
	}
	return(len);
}

int _printf(const char *format, ...)
{
	va_list args;
	int i, str_len;

	va_start(args, format);
	
	for(i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if(format[i] == '%')
			{
				_putchar('%');
				str_len++;
			}
			else if(format[i] == 'c')
			{
				_putchar(va_arg(args, int));
				str_len++;
			}
			else if(format[i] == 's')
			{
				str_len += _print_s(va_arg(args, const char*));
			}
		}
		else
		{
			_putchar(format[i]);
			str_len++;
		}
	}
	va_end(args);
	return(str_len);
}
