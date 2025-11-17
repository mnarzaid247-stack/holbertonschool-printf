#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_string(va_list args);
int print_int(va_list args);
int print_char(va_list args);
int print_percent(va_list args);
typedef struct type_tt
{
char c;
int (*p)(va_list);
} type_t;

#endif
