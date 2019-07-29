#include <unistd.h>
#include <stdarg.h>
#include "holberton.h"
/**
* conv - Handles conversion specifiers for _printf
* @format: Format string.
* @i: Current position of format.
* @c: Printed character count.
* @list: List of arguments.
* Return: 1 if conversion handled, 0 otherwise.
*/
short conv(const char *format, int *i, int *c, va_list *list)
{
	char ch, *str;
	int num, len;

	switch (format[*i])
	{
		case 'c':
			ch = (char)va_arg(list, int);
			write(1, &ch, 1);
			(*i)++;
			(*c)++;
			return (1);
		case 's':
			str = va_arg(list, char *);
			if (!str)
				str = "(null)";
			len = _strlen(str);
			write(1, str, len);
			(*i)++;
			(*c) += len;
			return (1);
		case 'd':
		case 'i':
			num = va_arg(list, int);
			num = print_number(num);
			(*i)++;
			(*c) += num;
			return (1);
		case '%':
			return (0);
		default:
			(*i)--;
			return (0);
	}
}
