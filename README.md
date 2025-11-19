# _printf

Implementation of the C standard library function `printf` (named `_printf`).

This repository contains a custom implementation of `_printf` that supports a subset of the standard conversion specifiers and is implemented as an educational project.

## Overview

`_printf` is a variadic function that formats and writes output to `stdout`. It mirrors the behavior of the standard `printf` for the supported specifiers and returns the number of characters printed (or a negative value on error).

This project is intended as a learning exercise in C: variadic functions, function pointers, and low-level I/O.

## Features / Supported specifiers

The current implementation supports the following conversion specifiers:

- `%s` — print a null-terminated string
- `%d` / `%i` — print a signed integer (decimal)
- `%c` — print a character
- `%%` — print a literal percent sign

If an unsupported specifier is encountered, `_printf` prints the percent sign and the following character literally (mirroring a simple fallback behavior).

## API

Header: `main.h` (included in this repository)

Prototype:

```c
int _printf(const char *format, ...);
```

Parameters:

- `format` — A C string that contains the text to be written, optionally containing embedded format specifiers starting with `%`.

Return value:

- On success, returns the number of characters printed.
- On error (for example, `format == NULL`), returns `-1`.

Notes on variadic arguments: `_printf` uses `stdarg.h` (`va_list`, `va_start`, `va_arg`, `va_end`) to access the variable argument list. The variadic parameters themselves are not named in the prototype and therefore are described in the function documentation rather than as `@param` entries.

## Example usage

Create a small test file `main.c`:

```c
#include "main.h"
#include <stdio.h>

int main(void)
{
	int len;

	len = _printf("Hello %s! You have %d new messages%c\n", "Alice", 5, '!');
	_printf("Printed %d characters\n", len);
	return (0);
}
```

Compile and run (macOS / Unix/GCC):

```sh
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o my_printf
./my_printf
```

Replace `*.c` with the appropriate source files in the repository if needed.

## Implementation notes

- The implementation uses a small dispatch table (array of structs) that maps conversion specifier characters to handler functions.
- Each handler consumes one argument from the `va_list` and returns the number of characters it printed.
- Low-level `write(1, ...)` is used for output, avoiding `printf` to remain independent of the standard formatted output functions.
- The function returns `-1` when the `format` pointer is `NULL`.

## Project layout

- `_printf.c` — main function and helper(s)
- `main.h` — function prototypes and type definitions
- `print_string.c`, `print_int.c`, `print_char.c`, `print_percent.c` — conversion handlers
- `README.md` — this file

## Style and quality gates

- Prefer small, well-named helper functions for each conversion specifier.
- Keep handlers side-effect free beyond writing their output and returning length.
- Check for edge cases like `NULL` strings in `%s` handlers.

## Contact

Authors: Manar Alzhrano and Aljawharah Saad

For questions or to report issues, open an issue in the repository.


