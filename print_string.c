#include "main.h"

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
return count;
}
