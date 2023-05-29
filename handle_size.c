#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Success
 */
int get_size(const char *format, int *i)
{
	int a = *i + 1, b = 0;

	if (format[a] == 'l')
		b = S_LONG;
	else if (format[a] == 'h')
		b = S_SHORT;

	if (b == 0)
		*i = a - 1;
	else
		*i = a;

	return (b);
}
