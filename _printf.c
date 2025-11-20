#include "main.h"
static type_t table[] = {
	{'s', print_string},
	{'d', print_int},
	{'c', print_char},
	{'%', print_percent},
	{'i', print_int},
	{'b', print_binary},
	{'u', print_unsigned},
	{'o', print_octal},
	{'x', print_lower},
	{'X', print_upper},
	{'\0', NULL},
};

/**
* format_handler - helper function to process format specifiers.
* @i: current index in format string.
* @format: format string.
* @args: va_list of arguments.
* @table: array of type_t mapping specifiers to functions.
* Return: updated total number of characters printed.
*/


int format_handler(int i, const char *format, va_list args, type_t table[])
{
int found;

int j;

int total = 0;

		if (format[i + 1] == '\0')
		{
			return (-1);
		}
		found = 0;
		for (j = 0 ; table[j].p != NULL ; j++)
		{
			if (format[i + 1] == table[j].c)
			{
				found = 1;
				total += table[j].p(args);
				break;
			}
		}
		if (found)
			i++;
		else if (!found)
		{
			write(1, &format[i], 1);
			total = total + 1;
			if (format[i + 1] != '\0')
			{
				write(1, &format[i + 1], 1);
				total = total + 1;
				i++;
			}
		}
return (total);
}

/**
* _printf - function that produces output according to a format.
* @format: format string.
*
* Return: number of characters printed.
*/
int _printf(const char *format, ...)
{
va_list args;
int i;
int total = 0;
int index = 0;
int added;
char buffer[1024];

if (format == NULL)
	return (-1);

va_start(args, format);
for (i = 0 ; format[i] != '\0' ; i++)
{
	if (format[i] == '%')
	{
		if (index > 0)
		{
			write(1, buffer, index);
			index = 0;
		}
		added = format_handler(i, format, args, table);

		if (added == -1)
		{
			va_end(args);
			return (-1);
		}
		total = total + added;
		i++;
	}
	else
	{
		buffer[index++] = format[i];
		total++;
		if (index == 1023)
		{
			write(1, buffer, index);
			index = 0;
		}
	}
}
if (index > 0)
{
	write(1, buffer, index);
}
va_end(args);
return (total);
}
