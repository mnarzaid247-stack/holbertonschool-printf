#include "main.h"
/**
* print_string - function that prints a string.
* @args: va_list containing the string to print.
* Return: number of characters printed.
*/
int print_string(va_list args)
{
char *str = va_arg(args, char *);
int i, count = 0;
if (str == NULL)
str = "(null)";
for (i = 0; str[i] != '\0'; i++)
{
write(1, &str[i], 1);
count++;
}
return (count);
}
