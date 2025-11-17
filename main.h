#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_string (char *str);
int print_number (int n);

typedef struct type
{
char c;
int (*p)(va_list);
} type;

#endif
