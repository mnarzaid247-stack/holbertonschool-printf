#include "main.h"

static int print_octal_rec(unsigned int n)
{
int count = 0;
char c;
if (n / 8)
	count = count + print_octal_rec(n / 8);
c = (n % 8) + '0';
write (1 , &c, 1);
return ( count + 1);
}

int print_octal(va_list args)
{
unsigned int n =va_arg(args,unsigned  int);
int count = 0;
if (n == 0)
{
write(1, "0", 1);
	return 1;
}
count = print_octal_rec(n);
return (count);
}
