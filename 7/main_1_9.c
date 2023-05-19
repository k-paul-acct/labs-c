#include <stdio.h>

#define PI 3.14159265358979323846
#define CIRCLE_AREA(radius) (PI * (radius) * (radius))

int main() {
    double radius = 5.0;
    printf("Circle area with radius %lf is %lf\n", radius, CIRCLE_AREA(radius));
    return 0;
}