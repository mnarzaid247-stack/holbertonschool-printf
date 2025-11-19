#include "main.h"
/**
* print_upper - function that prints a unsigned hexadecimal in uppercase.
* @args: va_list containing the unsigned integer to print.
* Return: number of characters printed.
*/
int print_upper(va_list args)
{
unsigned int n = va_arg(args, unsigned int);

int count = 0;

char hex_digits[] = "0123456789ABCDEF";

char buffer[32];

int i = 0;

if (n == 0)
{
	write(1, "0", 1);
}
while (n > 0)
{
	buffer[i++] = hex_digits[n % 16];
	n /= 16;
}
while (i > 0)
{
	write(1, &buffer[--i], 1);
	count++;
}
return (count);
}
