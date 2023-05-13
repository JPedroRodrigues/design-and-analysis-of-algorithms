#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


int busca_binaria_recursiva(int v[], int inicio, int len, int elemento)
{
    if (inicio > len -1) {
        return -1;
    }
    else {
        int meio = (inicio + len - 1) / 2;

        if(elemento == v[meio]) {
            return meio;
        }
        else if (elemento > v[meio]) {
            busca_binaria_recursiva(v, meio + 1, len, elemento);
        }
        else {
            busca_binaria_recursiva(v, inicio, meio, elemento);
        }
    }
}


void insertion_sort(int v[], int len)
{
    for (int i = 0; i < len; i++) {
        int elemento = v[i];
        int j = i - 1;

        bool encontrou = false;

        while (j >= 0 && !encontrou) {
            if (v[j] > elemento) {
                v[j + 1] = v[j];

                j--;
            }
            else {
                encontrou = true;
            }
        }
        v[j + 1] = elemento;
    }
}


int main()
{
    srand(time(NULL));

    int v[10];

    for (int i = 0; i < 10; i++) {
        v[i] = rand() % 100;
    }

    int len = sizeof(v) / sizeof(int);

    insertion_sort(v, len);

    printf("Vetor = [%d", v[0]);
    for (int i = 1; i < len; i++) {
        printf(", %d", v[i]);
    }
    printf("]\n");

    int elemento;
    printf("Elemento que deseja encontrar: ");
    scanf("%d", &elemento);

    printf("O elemento %d se encontra na posição %d.\n", elemento, busca_binaria_recursiva(v, 0, len, elemento));

    return 0;
}
