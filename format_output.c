#include "main.h"
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i = 0, c;
	char *s;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == '\0')
				break;

			if (*format == '%')
			{
				putchar('%');
				i++;
			}
			else if (*format == 'c')
			{
				c = va_arg(args, int);
				putchar(c);
				i++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				while (*s != '\0')
				{
					putchar(*s);
					i++;
					s++;
				}
			}
		}
		else
		{
			putchar(*format);
			i++;
		}

		format++;
	}
	va_end(args);
	return (i);
}
