#include "main.h"
/**
 * handle_specifiers - Matches a conversion specifier with
 *                     a corresponding conversion function.
 * @specifier: A pointer to a potential conversion specifier.
 *
 * Return: If a conversion function is matched - a pointer to the function.
 *         Otherwise - NULL.
 */
void handle_specifiers(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'u':
					{
						unsigned int u_value = va_arg(args, unsigned int);

						printf("%u\n", u_value);
						break;
					}
				case 'o':
					{
						unsigned int o_value = va_arg(args, unsigned int);

						printf("%o\n", o_value);
						break;
					}
				case 'x':
					{
						unsigned int x_value = va_arg(args, unsigned int);

						printf("%x\n", x_value);
						break;
					}
				case 'X':
					{
						unsigned int X_value = va_arg(args, unsigned int);

						printf("%X\n", X_value);
						break;
					}
				default:
					{
						putchar(*format);
						break;
					}
			}
		}
		else
		{
			putchar(*format);
		}
		format++;
	}
	va_end(args);
}
