#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define tam_a 5
#define tam_b 4

/*
 * Imprime um vetor e seus elementos.
 * Parâmetro v[]: vetor cujos valores serão impressos.
 * Parâmetro n: quantidade de elementos presentes no vetor v[],
 */
void mostra(int v[], int n) {
    int i;

    printf("Vetor = [%d", v[0]);

    for (i = 1; i < n; i++) {
        printf(", %d", v[i]);
    }

    printf("]\n");
}


/*
 * Verifica se existe um elemento repetido em um vetor de inteiros.
 * Parâmetro v[]: vetor a ser analisado;
 * Parâmetro elemento: número cuja repetição é verificada no vetor v[]
 * Parâmetro n: quantidade de valores que serão percorridos durante a verificação 
 */
bool elemento_repetido(int v[], int elemento, int n)
{
    int repetido = 1;

    for(int i = 0; i < n; i++) {
        if (elemento == v[i]) {
            repetido++;
            if (repetido > 1) {
                return true;
            }
        }
    }
    return false;
}


/*
 * Imprime o conjunto união a partir de dois vetores, A e B.
 * Parâmetro va[]: vetor A.
 * Parâmetro tamA: espaço alocado para o vetor A.
 * Parâmetro vb[]: vetor B.
 * Parâmetro tamB: espaço alocado para o vetor B.
 */
void uniao_conjuntos(int va[], int tamA, int vb[], int tamB)
{
    int uniao[9];
    int i = 0, ia, ib;

    // Vetor A
    for (ia = 0; ia < tamA; ia++) {
        if (ia == 0) {
            uniao[i] = va[ia];
            i++;
        }
        else if (ia > 0 && !elemento_repetido(uniao, va[ia], i)) {
            uniao[i] = va[ia];
            i++;
        }
    }
    // Vetor B
    for (ib = 0; ib < tamB; ib++) {
        if(!elemento_repetido(uniao, vb[ib], i)) {
            uniao[i] = vb[ib];
            i++;
        }
    }

    mostra(uniao, i);
}


int main()
{
    int a[tam_a];
    int b[tam_b];
    int i;

    srand(time(NULL));

    for(i = 0; i < tam_a; i++) {
        a[i] = rand() % 10 + 1;
    }

    for(i = 0; i < tam_b; i++) {
        b[i] = rand() % 10 + 1;
    }

    mostra(a, tam_a);
    mostra(b, tam_b);
    uniao_conjuntos(a, tam_a, b, tam_b);
    return 0;
}
