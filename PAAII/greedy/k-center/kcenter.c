/**
 * K-Centers Problem
 * 
 * Name                               RA
 * Gustavo Vilela Mitraud             10400866              
 * João Pedro Rodrigues Vieira        10403595          
 * Sabrina Midori F. T. de Carvalho   10410220
 * 
 * Course: Design and Analysis of Algorithms II
 * Professor: Leonardo Takuno
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int origin;
    int destiny;
    int distance;
} Distance;


typedef struct {
    int id;
    char name[200];
    int isCenter;
    Distance distancies[20];
} Faculty;


Distance min(Distance x, Distance y) { return x.distance < y.distance ? x : y; }
Distance max(Distance x, Distance y) { return x.distance > y.distance ? x : y; }


Faculty *kCenter(int k, Faculty *f, int n) {
    int index = 0;
    
    Distance minimum;
    Distance maximum = f[0].distancies[1];  // selecting the first building as a center

    Faculty *centers = (Faculty *) malloc(k * sizeof(Faculty));

    for (int i = 0; i < k; i++) {
        // The center will be the the building with the maximum minimum distance from the other centers
        f[maximum.origin - 1].isCenter = 1;
        centers[i] = f[maximum.origin - 1];

        maximum.distance = 0;

        for (int j = 0; j < n; j++) {
            if (f[j].isCenter == 1) continue;

            // getting the minimum distance of each building from the centers            
            minimum = f[j].distancies[0];

            while (index <= i) {
                minimum = min(minimum, f[j].distancies[centers[index].id - 1]);
                index++;
            }
            index = 0;

            // getting the maximum distance from the recently calculated minimum
            maximum = max(minimum, maximum);
        }
    }
    return centers;
}


int main() {
    FILE *f = fopen("./input.txt", "r");

    if (f == NULL) {
        printf("Error finding the input file.\n");
    }

    int n, k;
    char newLine;

    fscanf(f, "%d %d", &n, &k);
    fscanf(f, "%c", &newLine);

    Faculty *buildings = (Faculty *) malloc(n * sizeof(Faculty));
    Faculty fc;

    for (int i = 0; i < n; i++) {
        fc.id = i + 1;
        fgets(fc.name, sizeof(fc.name), f);
        fc.isCenter = 0;
        buildings[i] = fc;
    }

    int m, u, v, d;

    fscanf(f, "%d", &m);

    for (int i = 0; i < m; i++) {
        fscanf(f, "%d %d %d", &u, &v, &d);
        
        buildings[u - 1].distancies[v - 1].origin = u;
        buildings[u - 1].distancies[v - 1].destiny = v;
        buildings[u - 1].distancies[v - 1].distance = d;

        buildings[v - 1].distancies[u - 1].origin = v;
        buildings[v - 1].distancies[u - 1].destiny = u;
        buildings[v - 1].distancies[u - 1].distance = d;
    }

    fclose(f);

    f = fopen("output.txt", "w");

    Faculty *centers = kCenter(k, buildings, n);

    printf("=== %d Centers ===\n", k);
    for (int i = 0; i < k; i++) {
        printf("| %d.\n", i + 1);
        printf("| ID: %d\n", centers[i].id);
        printf("| Name: %s\n", centers[i].name);
        fprintf(f, "%s", centers[i].name);
    }

    fclose(f);
    free(buildings); free(centers);
    return 0;
}