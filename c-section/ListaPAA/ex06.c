#include <stdio.h>
#include <stdbool.h>
#include <math.h>

float calculatePi() {
    int k = 1;
    double pi = 4;
    double pi1 = 0;
    double element = 0, difference = 0;

    while (true) {
        element = 4.0 * (pow(-1.0, k) / (2.0 * k + 1));
        k++;

        pi += element;
        pi1 = pi + element;

        difference = fabs(pi - pi1);
        if (difference < 0.00001) return pi1;
    }
}

int main() {
    printf("Valor de PI: %f\n", calculatePi());
    return 0;
}