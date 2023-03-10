#include <stdio.h>
#include <stdbool.h>

#define tam 10

/*
 * Função que retorna true caso haja a repetição de um elemento em um vetor e false caso contrário.
 * Parâmetro v[]: vetor analisado;
 * Parâmetro valor: elemento cuja existência de repetição será verificada;
 * Parâmetro quantidade: número de espaços de memória do vetor v[].
 */
bool valores_diferentes(int v[], int valor, int quantidade)
{
    int repeticao = 0;

    for(int i = 0; i < quantidade; i++) {
        if (valor == v[i]) {
            repeticao++;
            if (repeticao > 0) {
                return false;
            }
        }
    }
    return true;
}


int main()
{
    int vetor[tam], i, qtd = 0;

    for (i = 0; i < tam; i++) {
        printf("Digite um número inteiro: ");
        scanf("%d", &vetor[i]);
        if (valores_diferentes(vetor, vetor[i], i)) {
            qtd++;
        }
    }

    printf("Quantidade de números distintos: %d.\n", qtd);
    return 0;
}
