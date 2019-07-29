#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
int _printf(const char *format, ...);
int _strlen(char *s);
unsigned int print_number(int n);
int _putchar(char c);
short conv(const char *format, int *i, int *c, va_list *list);

#endif /* HOLBERTON_H */
