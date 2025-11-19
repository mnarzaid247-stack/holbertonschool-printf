#include "main.h"

static int print_int_rec(unsigned int n)
{
int count = 0;
char c;
if (n / 10)
	{
        count = count + print_int_rec(n / 10);
	}
	c = (n % 10) + '0';
        write (1, &c, 1);
return (count + 1);
}

int print_unsigned (va_list args)
{
unsigned int n = va_arg(args,unsigned int);
int count = 0;
if (n == 0)
	{
	write (1, "0", 1);
	return 1;
	}
count = count + print_int_rec(n);
return (count);
}
