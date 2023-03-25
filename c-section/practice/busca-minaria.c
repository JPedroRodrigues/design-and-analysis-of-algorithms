#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void mostrar_vetor(int v[], int n)
{   
    printf("Vetor = [%d", v[0]);

    for (int i = 1; i < n; i++) {
        printf(", %d", v[i]);
    }

    printf("]\n");
}


int main()
{   
    // Inicializar o contador automático
    srand(time(NULL));

    // Receber a quantidade de elementos que serão alocados no vetor
    int qtd;

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &qtd);

    int *vetor = malloc(qtd * sizeof(int));

    // Realizar uma leitura de números aleatórios em ordem crescente
    for (int i = 0; i < qtd; i++) {
        vetor[i] = rand() % 10 + 10 * i;
    }

    mostrar_vetor(vetor, qtd);

    return 0;
}