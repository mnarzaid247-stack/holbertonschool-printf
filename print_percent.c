#include "main.h"

int print_percent(va_list args)
{
char c = '%';
write(1, &c, 1);
return 1;
}
