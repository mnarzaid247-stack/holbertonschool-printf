#include "main.h"

int print_percent(va_list args)
{
char c = '%';
(void)args;
write(1, &c, 1);
return 1;
}
