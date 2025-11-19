#include "main.h"
/**
* print_percent - function that prints a percent sign.
* @args: va_list (not used).
* Return: number of characters printed (1).
*/
int print_percent(va_list args)
{
char c = '%';
(void)args;
write(1, &c, 1);
return (1);
}
