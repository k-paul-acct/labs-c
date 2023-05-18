#include <stdio.h>
#include <stdlib.h>

typedef struct car {
    char *brand;
    int mileage;
    char *number;
} car;

car *car_new();
void car_read(car *c);
void car_print(car *c);
void car_free(car *c);

int main() {
    car *cars[5];

    for (int i = 0; i < 5; ++i) cars[i] = car_new();

    car_read(cars[1]);
    car_print(cars[1]);

    for (int i = 0; i < 5; ++i) car_free(cars[i]);

    return 0;
}

car *car_new() {
    car *c = malloc(sizeof(car));
    char *number = malloc(20 * sizeof(char));
    char *brand = malloc(100 * sizeof(char));

    c->mileage = 0;
    c->brand = brand;
    c->number = number;

    return c;
}

void car_read(car *c) {
    char newline;
    printf("Enter car brand: ");
    fgets(c->brand, 20, stdin);

    printf("Enter car mileage: ");
    scanf("%d", &(c->mileage));
    while ((newline = getchar()) != '\n') {
    }

    printf("Enter car number: ");
    fgets(c->number, 20, stdin);
}

void car_print(car *c) {
    printf("Car brand: %s", c->brand);
    printf("Car mileage: %d\n", c->mileage);
    printf("Car number: %s", c->number);
}

void car_free(car *c) {
    if (c != NULL) {
        if (c->brand != NULL) free(c->brand);
        if (c->number != NULL) free(c->number);
        free(c);
    }
}