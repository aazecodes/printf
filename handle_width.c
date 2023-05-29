#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: int
 */
int get_width(const char *format, int *i, va_list list)
{
	int a, b = 0;

	for (a = *i + 1; format[a] != '\0'; a++)
	{
		if (is_digit(format[a]))
		{
			b *= 10;
			b += format[b] - '0';
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
