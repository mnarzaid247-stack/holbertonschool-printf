#include "main.h"
/**
* print_octal_rec - helper function to print an unsigned integer
* in octal recursively.
* @n: unsigned integer to print.
* Return: number of characters printed.
*/
static int print_octal_rec(unsigned int n)
{
int count = 0;

char c;

if (n / 8)
	count = count + print_octal_rec(n / 8);
c = (n % 8) + '0';
write(1, &c, 1);
return (count + 1);
}
/**
* print_octal - function that prints an unsigned integer in octal.
* @args: va_list containing the unsigned integer to print.
* Return: number of characters printed.
*/
int print_octal(va_list args)
{
unsigned int n = va_arg(args, unsigned  int);

int count = 0;

if (n == 0)
{
write(1, "0", 1);
	return (1);
}
count = print_octal_rec(n);
return (count);
}
