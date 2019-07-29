#include "holberton.h"
/**
 * rot13 - encodes into root13
 * @cypher: translation
 *   (* a blank line
 *    * Description: Longer description of the function)?
 *    (* section header: Section description)*
 *     * Return: printcounter
 *
 */
int rot13(char *cypher)
{
	int a;
	int b;
	int printCounter = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char trans[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
​
​
	for (a = 0; cypher[a] != '\0'; a++)
	{
		for (b = 0; b <= 52; b++)
		{
			if (cypher[a] == in[b])
			{
				_putchar(trans[b]);
				printCounter++;
				break;
			}
		}
		if (b == 53)
		{
			_putchar(cypher[a]);
		}
	}
	return (printCounter);
}
