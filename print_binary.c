#include "main.h"
/**
* print_binary - function that prints an unsigned integer in binary.
* @args: va_list containing the unsigned integer to print.
* Return: number of characters printed.
*/
int print_binary(va_list args)
{
int count = 0;

int start = 0;

int bit;

unsigned int i = va_arg(args, unsigned int);

if (i == 0)
	{
	write(1, "0", 1);
	return (1);
	}
for (bit = 31 ; bit >= 0 ; bit--)
	{
	int current_bit = (i >> bit) & 1;

	if (start == 0 && current_bit == 0)
		continue;
	if (start == 0 && current_bit == 1)
		{
		start = 1;
		count++;
		write(1, "1", 1);
		continue;
		}
	if (start == 1)
		{
		if (current_bit == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		count++;
		}
	}
return (count);
}
