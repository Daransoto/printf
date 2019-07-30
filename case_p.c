#include "holberton.h"
#include <unistd.h>
/**
* case_p - print address
* @ptr: pointer
* Return: print counts
*/
int case_p(int *ptr)
{
	int counter = 0;

	counter += write(1, "0x", 2);
	counter += _printf("%x", ptr);
	return (counter);
}
