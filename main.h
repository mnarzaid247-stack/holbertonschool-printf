#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct type_tt - mapping from a format specifier to its handler
 * @c: the format specifier character (e.g., 's', 'd', 'c', '%')
 * @p: pointer to a function that handles printing for this specifier
 */
typedef struct type_tt
{
char c;
int (*p)(va_list);
} type_t;

int _printf(const char *format, ...);
int print_string(va_list args);
int print_int(va_list args);
int print_char(va_list args);
int print_percent(va_list args);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_lower(va_list args);
int print_upper(va_list args);
int format_handler(int i, const char *format, va_list args,
type_t table[]);
void flush_buffer(void);
void buffered_write(char c);

#endif /* MAIN_H */
