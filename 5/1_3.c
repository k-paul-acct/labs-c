#include <stdio.h>

int f(int x);

int main() {
    for (int i = -5; i < 5; ++i) {
        printf("7 - %d = %d\n", i, f(i));
    }

    return 0;
}

int f(int x) { return 7 - x; }