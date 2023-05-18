#include <stdio.h>

typedef struct detail {
    char *name;
    int price;
    int quantity;
} detail;

int main() {
    detail details[] = {
        {"d1", 10, 60}, {"d2", 20, 61}, {"d3", 30, 62}, {"d4", 40, 63}, {"d5", 50, 64},
        {"d6", 60, 65}, {"d7", 70, 66}, {"d8", 80, 67}, {"d9", 90, 68}, {"d10", 100, 69},
    };
    int max_price = 0;
    int max_index = 0;

    for (int i = 0; i < 10; ++i) {
        if (details[i].price > max_price) {
            max_price = details[i].price;
            max_index = i;
        }
    }

    printf("Max price: %s\n", details[max_index].name);

    return 0;
}