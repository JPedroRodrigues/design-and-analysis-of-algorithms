#include <stdio.h>
#include <stdbool.h>

#define tam 10

/*
 * Função que retorna true caso haja a repetição de um elemento em um vetor e false caso contrário.
 * Parâmetro v[]: vetor analisado;
 * Parâmetro valor: elemento cuja existência de repetição será verificada;
 * Parâmetro quantidade: número de espaços de memória do vetor v[].
 */
bool numero_repetido(int v[], int valor, int quantidade)
{
    int repeticao = 0;

    for(int i = 0; i < quantidade; i++) {
        if (valor == v[i]) {
            repeticao++;
            if (repeticao > 0) {
                return true;
            }
        }
    }
    return false;
}


/*
 * Função que retorna a quantidade de elentos diferentes em um vetor.
 * Parâmetro v[]: vetor a ser analisado.
 * Parâmetro tamanho: quantidade de elementos que o vetor possui.
 */
int valores_diferentes(int v[], int tamanho) {
    int qtd = 0;

    for (int i = 0; i < tam; i++) {
        printf("Digite um número inteiro: ");
        scanf("%d", &v[i]);
        if (!numero_repetido(v, v[i], i)) {
            qtd++;
        }
    }
    return qtd;
}


int main()
{
    int vetor[tam], i;

    printf("Quantidade de números distintos: %d.\n", valores_diferentes(vetor, tam));
    return 0;
}
