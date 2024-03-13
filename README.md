## About the project

For this project we are asked to replicate the general behavior of the famous printf function, and create a library for it use.
We will learn about variadic arguments and if you plan to make the bonus, the implementation of
an structure will help you a lot.

For the mandatory part you will implement the following conversions:

- `%c` Print single character.
- `%s` Print a string.
- `%p` Print a pointer adress.
- `%d` Print a signed integer.
- `%i` Print a signed integer too.
- `%u` Print an unsigned integer.
- `%x` Print unsigned integer in hexadecimal format(lowercase).
- `%X` Print unsigned integer in hexadecimal format(uppercase).
- `%%` Print % symbol.

For the Bonus part you will implement the following flags:

- `-` To justify the result to the left.
- `0` To add zeros instead of spaces as pad.
- `.(number)` To add precision, for integers(%d, %i, %u, %x, %X) brings an minimum number of digits to be printed. If the value is shorter than this number, the result is padded with zeros. The value will not truncate even if it is longer. A precision 0 means that no character is print for the value 0. With %s, it will the maximum number of characters to be printed. 0 is the default value if the period is specified without a explicit number.
- `.(*)` To add precision specifying an extra integer argument preceding the argument that has to be formatted.
- `#` To add the prefix 0x or 0X for hexadecimals number (%x or %X).
- `(space)` To add and extra space if there are not an explicit sign.
- `+` To force to print the plus signal for positive number.
- `*` To specified the width as an extra integer argument preceding the argument that has to be formatted.
- `(number)` To add the minimum number of characters to be printed. If the value is shorter than this number, the result is padded with spaces. The value will not truncate even if the result is larger.

## Usage

1. Clone the repository

```bash
git clone https://github.com/SebasNadu/42_ft_printf.git && cd 42_ft_printf
```

2. Remove the .git folder

```bash
rm -rf .git
```

3. Compile and create the library (libftprintf.a)

```bash
make
```

4. Copy the files to your project folder and include the header file in your code.

```c
#include "42_ft_prinf/include/ft_printf.h"
```

5. Compile your project with the ft_printf library

```c
cc -Wall -Wextra -Werror
```
