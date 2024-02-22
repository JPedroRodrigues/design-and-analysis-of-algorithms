#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define tam 5

/*
 * Função que retorna true caso haja a repetição de um elemento em um vetor e false caso contrário.
 * Parâmetro v[]: vetor analisado;
 * Parâmetro numero: elemento cuja existência de repetição será verificada;
 * Parâmetro len: número de espaços de memória do vetor v[].
 */
bool numero_repetido(int v[], int numero, int len)
{
    int repeticao = 0;

    for (int pos = 0; pos < len; pos++) {
        if (numero == v[pos]) {
            repeticao++;
            if (repeticao > 0) {
            return true;
            }
        }
    }
    return false;
}

/*
 * Função que retorna o índice de um valor x desejado.
 * Parâmetro vetor: vetor a ser analisado;
 * Parâmetro x: número cujo índice é desejado;
 * Parâmetro len: tamanho do vetor.
 */
int posx(int v[], int x, int len)
{   
    int i;
    for (i = 0; i < len; i++) {
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}

/*
 * Função que imprime um vetor e seus elementos no terminal.
 * Parâmetro v[]: vetor para impressão;
 * Parâmetro len: tamanho do vetor.
 */
void mostra_vetor(int v[], int len) {
    printf("Vetor = [%d", v[0]);

    for (int j = 1; j < tam; j++) {
        printf(", %d", v[j]);
    }
    printf("]\n");
}


int main()
{
    srand(time(NULL));

    int vetor[tam];
    int valor_x;

    printf("Digite um número inteiro de 0 a 10: ");
    scanf("%d", &valor_x);

    vetor[0] = rand() % 10 + 1;

    int i = 1;

    do {
        int numero_aleatorio = rand() % 10 + 1;
        if (!numero_repetido(vetor, numero_aleatorio, i)) {
            vetor[i] = numero_aleatorio;
            i++;
        }
    } while (i < tam);
    
    mostra_vetor(vetor, tam);

    printf("Valor x: %d.\n", valor_x);
    printf("Posição de x: %d.\n", posx(vetor, valor_x, tam));
    
    return 0;
}
