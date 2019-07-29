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
short conv2(const char *format, int *i, int *c, va_list *list);
short conv(const char *format, int *i, int *c, va_list *list)
{
	char ch, *str;
	unsigned int num, len;

	switch (format[*i])
	{
		case 'c':
			ch = (char)va_arg(list, int);
			write(1, &ch, 1);
			(*c)++;
			return (1);
		case 's':
			str = va_arg(list, char *);
			if (!str)
				str = "(null)";
			len = _strlen(str);
			write(1, str, len);
			(*c) += len;
			return (1);
		case 'd':
		case 'i':
			num = va_arg(list, int);
			num = print_number(num, 1);
			(*c) += num;
			return (1);
		case 'b':
			num = va_arg(list, int);
			(*c) += print_base(num, 2, 0);
			return (1);
		case 'o':
			num = va_arg(list, int);
			(*c) += print_base(num, 8, 0);
			return (1);
		case 'x':
			num = va_arg(list, int);
			(*c) += print_base(num, 16, 0);
			return (1);
		default:
			return (conv2(format, i, c, list));
	}
}
/**
* conv2 - Handles conversion specifiers for _printf
* @format: Format string.
* @i: Current position of format.
* @c: Printed character count.
* @list: List of arguments.
* Return: 1 if conversion handled, 0 otherwise.
*/
short conv2(const char *format, int *i, int *c, va_list *list)
{
	unsigned int num;

	switch (format[*i])
	{
		case 'X':
			num = va_arg(list, int);
			(*c) += print_base(num, 16, 1);
			return (1);
		case 'u':
			num = va_arg(list, int);
			num = print_number(num, 0);
			(*c) += num;
			return (1);
		case '%':
			return (0);
		default:
			(*i)--;
			return (0);
	}
}
