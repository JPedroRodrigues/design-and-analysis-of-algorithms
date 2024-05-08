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
    int ld;
} Faculty;


Distance min(Distance x, Distance y) { return x.distance < y.distance ? x : y; }
Distance max(Distance x, Distance y) { return x.distance > y.distance ? x : y; }


void kCenter(int k, Faculty *f, int n) {
    Faculty *centers = (Faculty *) malloc(k * sizeof(Faculty));
    centers[0] = f[0];  // selecting the first center
    int lc = 1;
    int index = 0;
    
    Distance minimum;
    Distance maximum = f[0].distancies[0];

    for (int i = 0; i < k; i++) {
        f[maximum.start - 1].isCenter = 1;
        centers[i] = f[maximum.start - 1];

        printf("New center[%d]!!\nid: %d\nname: %s\n", i, centers[i].id, centers[i].name);

        for (int j = 0; j < n; j++) {
            if (f[j].isCenter == 1) continue;
            
            minimum = f[j].distancies[0];

            while (index < i) {
                minimum = min(minimum, f[j].distancies[centers[index].id - 1]);
                index++;
            }

            printf("The minimum distance of building %d from centers", f[j].id);
            for (int m = 0; m <= i; m++) printf(" %d", centers[m].id);
            printf(": %d\n\n", minimum.distance);

            maximum = max(minimum, maximum);
        }
        index = 0;
    }
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
        fc.ld = 0;
        buildings[i] = fc;
    }

    int m, u, v, d;

    fscanf(f, "%d", &m);

    for (int i = 0; i < m; i++) {
        fscanf(f, "%d %d %d", &u, &v, &d);

        buildings[u - 1].distancies[buildings[u - 1].ld].start = u;
        buildings[u - 1].distancies[buildings[u - 1].ld].finish = v;
        buildings[u - 1].distancies[buildings[u - 1].ld].distance = d;

        buildings[v - 1].distancies[buildings[v - 1].ld].start = v;
        buildings[v - 1].distancies[buildings[v - 1].ld].finish = u;
        buildings[v - 1].distancies[buildings[v - 1].ld].distance = d;

        buildings[u - 1].ld++;
        buildings[v - 1].ld++;
    }

    // for (int i = 0; i < n; i++) {
    //     printf("id: %d\nname: %s\n", buildings[i].id, buildings[i].name);
    //     print(buildings[i].distancies, buildings[i].ld);
    //     printf("\n");
    // }

    fclose(f);

    kCenter(3, buildings, n);

    free(buildings);

    return 0;
}