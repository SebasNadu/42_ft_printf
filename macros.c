#include <stdio.h>

// gcc -dM -E macros.c > macros.txt

int main() {
    printf("GCC version: %d.%d.%d\n", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
    return 0;
}
