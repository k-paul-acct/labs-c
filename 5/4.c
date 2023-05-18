#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int read_numbers(int* a, int* b);
void print_menu();

int main() {
    while (1) {
        print_menu();
        int option, a, b;

        if (!scanf("%d", &option) || option == 5) exit(1);

        printf("Enter a and b:\n");
        if (!read_numbers(&a, &b)) exit(1);

        switch (option) {
            case 1:
                printf("%d^%d=%lf", a, b, pow(a, b));
                break;
            case 2:
                printf("%d*%d=%d", a, b, a * b);
                break;
            case 3:
                printf("%d%%%d=%d", a, b, a % b);
                break;
            case 4:
                printf("%s", a % b == 0 ? "a is multiple of b" : "a is not multiple of b");
                break;
            default:
                printf("Unknown option.");
        }

        putchar('\n');
    }
}

void print_menu() {
    printf("Choose an operation:\n");
    printf("\t1. a^b\n");
    printf("\t2. a*b\n");
    printf("\t3. a%%b\n");
    printf("\t4. a is a multiple of b\n");
    printf("\t5. Exit.\n");
}

int read_numbers(int* a, int* b) {
    if (scanf("%d %d", a, b) != 2) return 0;
    return 1;
}