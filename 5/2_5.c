#include <stdio.h>

int f1(int x);
int f2(int x);
double function(int (*f1)(int), int (*f2)(int), int x);

int main() {
    for (int i = -5; i < 5; ++i) {
        printf("(f1(%d) + f2(%d)) / f1(%d) = %lf\n", i, i, i, function(f1, f2, i));
    }

    return 0;
}

double function(int (*f1)(int), int (*f2)(int), int x) { return (f1(x) + f2(x)) / (double)f1(x); }
int f1(int x) { return 7 - x; }
int f2(int x) { return 5 * x - 32; }