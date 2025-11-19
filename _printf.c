#include "main.h"
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

type_t table[] = {
	{'s', print_string},
	{'d', print_int},
	{'c', print_char},
	{'%', print_percent},
	{'i', print_int},
	{'\0', NULL},
};
va_start(args, format);

if (format == NULL)
	return (-1);
for (i = 0 ; format[i] != '\0' ; i++)
{
	if (format[i] == '%')
	{
		int added = format_handler(i, format, args, table);
		
		if (added == -1)
			return (-1);
		total = total + added;
		i++;
	}
	else
	{
		write(1, &format[i], 1);
		total = total + 1;
	}
}
return (total);
}
