# ft_printf

A minimal re-implementation of the C standard library function `printf`, developed for the 42 School curriculum. It formats and prints data to the standard output and returns the number of characters printed.

## Overview

This project provides a subset of the behavior of `printf(3)` with a focus on correctness, robustness, and adherence to the subject constraints.
## Supported Conversions

- `%c` – print a single character
- `%s` – print a string
- `%p` – print a pointer address
- `%d` – print a signed decimal integer
- `%i` – print a signed decimal integer
- `%u` – print an unsigned decimal integer
- `%x` – print a number in lowercase hexadecimal
- `%X` – print a number in uppercase hexadecimal
- `%%` – print a literal percent sign

Behavior matches standard `printf` for the supported conversions where possible within the project scope.

## Function Prototype

```c
int ft_printf(const char *format, ...);
```

- Returns: the number of characters written, or a negative value on error

## Files

- `ft_printf.c` – main `ft_printf` entry point and format parsing
- `helper.c` – helper functions (integer to string conversions, hex formatting, etc.)
- `ft_printf.h` – public header with prototypes and includes
- `Makefile` – optional build script to produce a static library `libftprintf.a`


## Build

Using the provided Makefile:

```bash
make            # builds libftprintf.a
make clean      # remove object files
make fclean     # remove objects and library
make re         # rebuild from scratch
```

Manual build example (Unix/WSL/MinGW):

```bash
gcc -Wall -Wextra -Werror -c ft_printf.c helper.c
ar rcs libftprintf.a ft_printf.o helper.o
```

## Usage

Link the library and include the header in your program:

```c
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int count = ft_printf("Hello %s, dec=%d hex=%x ptr=%p %%\n", "world", 42, 42, (void*)0x1234);
    printf("\n(ft_printf printed %d chars)\n", count);
    return 0;
}
```

Compile and run:

```bash
gcc -Wall -Wextra -Werror -o demo main.c libftprintf.a
./demo 2> NUL || demo.exe
```

## Notes and Edge Cases

- Return value should equal the total number of characters written to stdout
- Properly handle `NULL` pointers for `%s` (commonly prints `(null)`) and `%p`
- Ensure integer conversions handle edge cases (e.g., `INT_MIN`, zero)
- No undefined behavior when encountering unsupported format specifiers; your parser should handle or reject them gracefully per your subject requirements

## Testing

Create quick sanity tests and compare against the system `printf` for supported specifiers:

```c
ft_printf("[%10s] [%c] [%d] [%u] [%x] [%X] [%p] [%%]\n", "str", 'A', -123, 123u, 0x2a, 0x2a, (void*)0);
```

Automate with scripts or unit tests to verify the printed output and the returned character count.

## Integration

- Include `ft_printf.h` in any translation unit that calls `ft_printf`
- Link against `libftprintf.a` (or your compiled objects) after your object files in the command line
- If integrating with `libft`, ensure there are no conflicting symbol names

## Acknowledgments

- Inspired by the original `printf(3)` and the 42 School ft_printf project.
