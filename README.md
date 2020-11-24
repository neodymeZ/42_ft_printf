# 42_ft_printf
Creating my version of stdlib printf function

## Usage
```
git clone <repo> <dir>
cd dir
make
```
Libftprintf.a library will be created.

To use the library, include "libftprintf.h" header to your source C files and compile with the relevant flags.

## Features
1. Conversions: c s p d i u x X o % n f g e;

*Additionally implemented: b conversion (to binary number representation).*

2. Flags: - + 0 space #;
3. Width, including dynamic with *;
4. Precision, including dynamic with *;
5. Length modifiers: l ll h hh z j t;

## Known bugs
1. Passing va_list by value leads to undefined behavior.

*Fix: pass it as pointer to avoid undefined behavior.*
