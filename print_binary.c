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
		buffered_write('0');
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
	buffered_write('1');
		continue;
		}
	if (start == 1)
		{
		if (current_bit == 1)
			buffered_write('1');
		else
			buffered_write('0');
		count++;
		}
	}
return (count);
}
