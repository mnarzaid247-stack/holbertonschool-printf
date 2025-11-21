#include "main.h"

/**
 * print_S - prints a string, but non-printable chars as \xHH
 * @args: va_list containing the string
 * Return: number of characters printed
 */
int print_S(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;
	int i;
	unsigned char c;
	char hex[2];

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		c = str[i];
		if (c >= 32 && c < 127)
		{
			buffered_write(c);
			count++;
		}
		else
		{
			buffered_write('\\');
			buffered_write('x');
			count += 2;

			/* Convert to uppercase hex, always 2 digits */
			hex[0] = "0123456789ABCDEF"[c / 16];
			hex[1] = "0123456789ABCDEF"[c % 16];

			buffered_write(hex[0]);
			buffered_write(hex[1]);
			count += 2;
		}
	}

	return (count);
}
