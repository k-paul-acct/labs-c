#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define RANGE_MIN 0
#define RANGE_MAX 10

int random_number();
void print_arr(int *arr, size_t n);

int calls = 0;
int numbers[N + 1] = {0};

int main() {
    for (int a = 0; a < 10; ++a) {
        srand(time(NULL));
        for (int i = 0; i < 1000; ++i) random_number();
    }

    printf("Function calls: %d\n", calls);
    printf("Numbers appearance:\n");
    for (int i = 0; i <= N; ++i) printf("%d - %d times\n", i, numbers[i]);

    return 0;
}

int random_number() {
    int n = rand() % (RANGE_MAX - RANGE_MIN + 1) + RANGE_MIN;
    ++calls;
    ++(numbers[n]);
    return n;
}