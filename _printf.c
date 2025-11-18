#include "main.h"
int _printf(const char *format, ...)
{
va_list args;
int i;
int found;
int j;
int tottal = 0;
va_start(args, format);
type_t table[] =
{
{'s' , print_string},
{'d', print_int},
{'c', print_char},
{'%', print_percent},
{'\0', NULL}
};
if (format == NULL)
return(-1);
for (i = 0 ; format[i] != '\0' ; i++)
{
if (format[i] == '%')
{
if (format[i + 1] == '\0')
{
write(1, &format[i], 1);
return(tottal + 1);
}
found = 0;
for (j = 0 ; table[j].c != '\0' ; j++)
{
if (format[i + 1] == table[j].c)
{
found = 1;
tottal = tottal + table[j].p(args);
break;
}
}
if (found)
i++;
else if (!found)
{
write(1, &format[i], 1);
tottal = tottal + 1;
if (format[i + 1] != '\0')
{
write(1, &format[i + 1], 1);
tottal = tottal + 1;
}
}
}
else
{
write(1, &format[i], 1);
tottal = tottal + 1;
}
}
return(tottal);
}
