#include "main.h"


static int print_int_recursive(int n)
{
int count = 0;
char digit;
if (n / 10)
count = count + print_int_recursive(n / 10);
digit = (n % 10) + '0';
write(1, &digit, 1);
return count + 1;
}

int print_int(va_list args)
{
int i = va_arg(args, int);
char c = '-';
int count = 0;
if (i < 0)
{
write (1, &c, 1);
count++;
i = -i;
}
count = count + print_int_recursive(i); 
return count;
}
