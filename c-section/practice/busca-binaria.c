#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 100


void mostra(int v[], int n)
{
    printf("[%d", v[0]);
    for (int i = 1; i < n; i++) {
        printf(", %d", v[i]);
    }
    printf("]\n");
}


int busca_binaria(int v[], int n, int e)
{
    int inicio, fim, meio;

    inicio = 0;
    fim = n - 1;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (e > v[meio]) {
            inicio = meio + 1;
        }

        else if (e < v[meio]) {
            fim = meio - 1;
        }
        else {
            return meio;
        }
    }
}


int main()
{
    srand(time(NULL));
    int vetor[tam];
    int qtd, elemento;

    printf("Digite a quantidade de elementos que deseja inserir no vetor: ");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++) {
        vetor[i] = rand() % 10 + 10*i;
    }

    printf("Vetor criado: ");
    mostra(vetor, qtd);

    printf("Digite um elemento que deseja encontrar neste vetor: ");
    scanf("%d", &elemento);

    printf("Posição do elemento %d: %d.\n", elemento, busca_binaria(vetor, qtd, elemento));

    return 0;
}