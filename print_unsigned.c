#include "main.h"
/**
 * print_int_rec - helper function to print an unsigned integer recursively.
 * @n: unsigned integer to print.
 * Return: number of characters printed.
 */
static int print_int_rec(unsigned int n)
{
	int count = 0;
	char c;

	if (n / 10)
	{
		count = count + print_int_rec(n / 10);
	}
	c = (n % 10) + '0';
	buffered_write(c);
	return (count + 1);
}
/**
 * print_unsigned - function that prints an unsigned integer.
 * @args: va_list containing the unsigned integer to print.
 * Return: number of characters printed.
 */
int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;

	if (n == 0)
	{
		buffered_write('0');
		return (1);
	}
	count = count + print_int_rec(n);
	return (count);
}
