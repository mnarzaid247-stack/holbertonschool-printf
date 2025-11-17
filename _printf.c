#include "main.h"

int _printf(const char *format, ...)
{
va_list args;
int i;
int j;
int tottal = 0;
va_start(args, format);
type_t table[] =
{
{'s' , print_string},
{'d', print_int},
{'c', print_char}
};
if (format == NULL)
return(-1);
for (i = 0 ; format[i] != '\0' ; i++)
{
if (format[i] == '%')
{
for (j = 0 ; j <= 3 ; j++)
{
if (format[i + 1] == table[j].c)
tottal = tottal + table[j].p(args);
i++;
}
}
}
}
