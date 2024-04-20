#include <stdio.h>
#include <stdlib.h>

void print(int *a, int n) {
    printf("[%d", a[0]);
    for (int i = 1; i < n; i++) printf(", %d", a[i]);
    printf("]\n");
}


int *fuelStops(int *stops, int n, int fuel, int *ls) {
    int *s = (int *) malloc(n * sizeof(int));

    int start = 0;

    for (int i = 1; i < n; i++) {
        if (stops[i] - start > fuel) {
            start = stops[i - 1];
            s[*ls] = start;
            *ls = *ls + 1;
        }
    }

    if (stops[n - 1] - start <= fuel) {
        s[*ls] = stops[n - 1];
        *ls = *ls + 1;
    } else printf("Unable to reach the last stop.\n");
    return s;
}


int main() {
    int n = 6;
    int stops[] = {1, 2, 3, 5, 6, 7};
    int fuel = 2;

    printf("Number of stops: %d\n", n);
    printf("Distance between gas stations: ");
    print(stops, n);
    printf("Maximum number of gas stations a car can pass: %d\n", fuel);

    int ls = 0;
    int *s = fuelStops(stops, n, fuel, &ls);

    printf("Result: ");
    print(s, ls);

    return 0;
}