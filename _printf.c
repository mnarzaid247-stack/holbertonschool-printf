#include "main.h"

int _printf(const char *format, ...)
{
va_list args;
int i;

va_start(args, format);
if (format == NULL)
return(-1);
for (i = 0 ; format[i] != '\0' ; i++)
{
if (format[i] == '%')
{
format[i + 1]
{'s' , print_string}
{'d', print_int}
{'c', print_char}
}
}
}
