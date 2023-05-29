#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: int
 */
int get_precision(const char *format, int *i, va_list list)
{
	int a = *i + 1, b = -1;

	if (format[a] != '.')
		return (b);
	b = 0;

	for (a += 1; format[a] != '\0'; a++)
	{
		if (is_digit(format[a]))
		{
			b *= 10;
			b += format[a] - '0';
		}
		else if (format[a] == '*')
		{
			a++;
			b = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = a - 1;
	return (b);
}
