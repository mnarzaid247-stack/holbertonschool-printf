#include "main.h"
/**
* print_int_recursive - helper function to print an integer recursively.
* @n: integer to print.
* Return: number of characters printed.
*/
static int print_int_recursive(unsigned int n)
{
int count = 0;

char digit;

	if (n / 10)
		count = count + print_int_recursive(n / 10);
	digit = (n % 10) + '0';
	buffered_write(digit);
return (count + 1);
}
/**
* print_int - function that prints an integer.
* @args: va_list containing the integer to print.
* Return: number of characters printed.
*/
int print_int(va_list args)
{
int i = va_arg(args, int);

char c = '-';

int count = 0;

unsigned int n;

if (i < 0)
{
	buffered_write(c);
count++;
n = -((unsigned int)i);
}
else
{
	n = i;
}
	count = count + print_int_recursive(n);
return (count);
}
