#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int start;
    int finish;
    int number;
} Activities;


void merge(Activities *a, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    Activities L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; ++i) L[i] = a[l + i];
    for (int j = 0; j < n2; ++j) R[j] = a[m + 1 + j];

    // Merge the temp arrays back into a[l..r]
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i].finish <= R[j].finish) {
            a[k] = L[i];
            ++i;
        } else {
            a[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of L[], is there are any
    while (i < n1) {
        a[k] = L[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        a[k] = R[j];
        ++j;
        ++k;
    }
}

// l is for left index and r is right index of the sub-array of a to be sorted
void mergeSort(Activities *a, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}


void print(Activities *a, int n) {
    for (int i = 0; i < n; ++i) printf("Activity: %d\nStart: %d, Finish: %d\n", a[i].number, a[i].start, a[i].finish);
    printf("\n");
}


Activities *selectActivities(Activities *a, int n, int *lb) {
    // Sort the struct array
    mergeSort(a, 0, n - 1);
    
    // Create solution array, that will store the activities that finish first and are compatible
    Activities *b = (Activities *)malloc(n * sizeof(Activities));
    
    b[0] = a[0];
    *lb = 1;
    int j = 0;

    for (int i = 1; i < n; ++i) {
        // if i and j are compatibles
        if (a[i].start >= a[j].finish) {
            b[*lb] = a[i];
            *lb = *lb + 1;
            j = i;
        }
    }
    return b;
}


int main() {

    Activities activities[11];
    int n = 11;

    // s: 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12
    activities[0].start = 1;
    activities[1].start = 3;
    activities[2].start = 0;
    activities[3].start = 5;
    activities[4].start = 3;
    activities[5].start = 5;
    activities[6].start = 6;
    activities[7].start = 8;
    activities[8].start = 8;
    activities[9].start = 2;
    activities[10].start = 12;

    // f: 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14
    for (int i = 0; i < 11; ++i) activities[i].finish = i + 4;

    // n: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
    for (int i = 0; i < 11; ++i) activities[i].number = i + 1;
    
    int lenAns = 0;
    Activities *ans = selectActivities(activities, n, &lenAns);
    print(ans, lenAns);
 
    return 0;
}