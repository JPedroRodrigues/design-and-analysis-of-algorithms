/**
 * Name                               RA
 * Gustavo Vilela Mitraud             10400866              
 * João Pedro Rodrigues Vieira        10403595          
 * Sabrina Midori F. T. de Carvalho   10410220
 * 
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int start;
    int finish;
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
    Faculty *centers = (Faculty *) malloc(k * sizeof(Faculty));
    centers[0] = f[0];  // selecting the first center
    int lc = 1;
    int index = 0;
    
    Distance minimum;
    Distance maximum = f[0].distancies[1];

    for (int i = 0; i < k; i++) {
        f[maximum.start - 1].isCenter = 1;
        centers[i] = f[maximum.start - 1];

        maximum.distance = 0;

        printf("New center[%d]!!\nid: %d\nname: %s\n", i, centers[i].id, centers[i].name);

        for (int j = 0; j < n; j++) {
            if (f[j].isCenter == 1) continue;
            
            minimum = f[j].distancies[0];

            while (index <= i) {
                minimum = min(minimum, f[j].distancies[centers[index].id - 1]);
                index++;
            }
            index = 0;

            printf("The minimum distance from building %d to centers", f[j].id);
            for (int m = 0; m <= i; m++) printf(" %d", centers[m].id);
            printf(": %d\n\n", minimum.distance);

            maximum = max(minimum, maximum);
        }
    }
    return centers;
}


void print(Distance *a, int n) {
    printf("[%d-%d-%d", a[0].start, a[0].finish, a[0].distance);
    for (int i = 1; i < n; i++) printf(", %d-%d-%d", a[i].start, a[i].finish, a[i].distance);
    printf("]\n");
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

        buildings[u - 1].distancies[v - 1].start = u;
        buildings[u - 1].distancies[v - 1].finish = v;
        buildings[u - 1].distancies[v - 1].distance = d;

        buildings[v - 1].distancies[u - 1].start = v;
        buildings[v - 1].distancies[u - 1].finish = u;
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