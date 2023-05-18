#include <stdio.h>

int f(int x);

int main() {
    for (int i = -5; i < 5; ++i) {
        printf("5 * %d - 32 = %d\n", i, f(i));
    }

    return 0;
}

int f(int x) { return 5 * x - 32; }