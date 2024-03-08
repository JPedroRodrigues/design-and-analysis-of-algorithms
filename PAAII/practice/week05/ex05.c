#include <stdio.h>
#include <stdbool.h>

/*
* Print the segments present in the sequence
* Time complexity: O(n²)
*/
void printSegment(int a[], int n) {
    int i = 0;
    int j = i + 1;
    
    printf("(%d", a[i]);
    while (true) {
        if (a[i] != a[j]) {
            printf(")");
            i = j;
            if (i < n && j < n) printf(", (");
        } else {
            if (i == j) printf("%d", a[j]);
            else printf(", %d", a[j]);
            j++;
        }

        if (i >= n && j >= n) break;
    }
    printf("\n");
}

/*
* Count the number of segments present in the sequence
* Time complexity: O(n²)
*/
int countSegments(int a[], int n) {
    int i = 0;
    int j = i + 1;
    int count = 0;

    while (true) {
        if (a[i] != a[j]) {
            i = j;
            count++;
        } else j++;
        if (i >= n && j >= n) break;
    }
    return count;
}


void print(int a[], int n) {
    printf("[%d", a[0]);
    for (int i = 1; i < n; i++) printf(", %d", a[i]);
    printf("] ");
}


int main() {
    int a1[] = {5, 2, 2, 3, 4, 4, 4, 4, 4, 1, 1};
    int a2[] ={3, 3, -1, -1, -1, 12, 12, 12, 3, 3};

    int len1 = sizeof(a1) / sizeof(int);
    int len2 = sizeof(a2) / sizeof(int);

    printf("A sequência ");
    print(a1, len1);
    printf("é composta por %d subsequências:\n", countSegments(a1, len1));
    printSegment(a1, len1);

    printf("\nA sequência ");
    print(a2, len2);
    printf("é composta por %d subsequências:\n", countSegments(a2, len2));
    printSegment(a1, len1);
    
    return 0;
}