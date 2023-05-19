#include "main_1_1.h"

#include <stdio.h>

int main() {
    printf("1.5 + 2.4 = %lf\n", sum(1.5, 2.4));
    return 0;
}

double sum(double a, double b) { return a + b; }