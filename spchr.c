#include "holberton.h"
#include <unistd.h>
int spchr(char *s)
{
	int c = 0;
	char zero = '0';
	while(*s)
	{
		if(*s < 32 || *s > 126)
		{
			c += write(1, "\\x", 2);
			if (*s < 16)
				c += write(1,&zero,1);
			c += _printf("%X",*s);
		}
		else
		{
			c += write(1,s,1);
		}
		s++;
	}
	return (c);
}
