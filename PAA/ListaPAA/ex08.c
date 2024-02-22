#include <stdio.h>
#include <stdbool.h>

bool isSubNumber(int p, int q) {
    if (p > q) return false;

    while (q != 0) {
        if (q % 10 == p % 10) {
            p /= 10;
            q /= 10;

            while (p != 0) {
                if (p % 10 != q % 10) return false;
                else {
                    p /= 10;
                    q /= 10;
                }
            }
            return true;
        }
        q /= 10;
    }
    return false;
}


int main() {
    int p, q;
    printf("Número p: "); scanf("%d", &p);
    printf("Número q: "); scanf("%d", &q);

    if (isSubNumber(p, q)) printf("P (%d) é subnúmero de Q (%d).\n", p, q);
    else printf("P (%d) NÃO é subnúmero de Q (%d).\n", p, q);

    return 0;
}