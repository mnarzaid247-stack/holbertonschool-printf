#include "main.h"

int _printf(const char *format, ...)
{
va_list args;
int i;
va_start(args, format);
type table[] =
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
type(format[i + 1])
}
}
}
