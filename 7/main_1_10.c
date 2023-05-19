#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define RANGE_MIN 1
#define RANGE_MAX 100

void random_fill(int *arr, size_t n);
void print_arr(int *arr, size_t n);

int main() {
#ifdef N
    int arr[N];

    srand(time(NULL));

    random_fill(arr, N);

    printf("Array:\n");
    print_arr(arr, N);
#else
    printf("No array size specified.");
#endif

    return 0;
}

void random_fill(int *arr, size_t n) {
    for (int *i = arr; i < arr + n; ++i) *i = rand() % (RANGE_MAX - RANGE_MIN + 1) + RANGE_MIN;
}

void print_arr(int *arr, size_t n) {
    for (int *i = arr; i < arr + n; ++i) printf("%d ", *i);

    putchar('\n');
}