#include <stdio.h>

int maior_numero(int sequencia)
{
    int numero, maior, segundo_maior, i = 1;

    for(i; i <= sequencia; i++)
    {
        printf("Digite um número inteiro: "); scanf("%d", &numero);
        
        if (i == 1)
        {
            maior = numero;
        }
        else if (numero > maior)
        {
            segundo_maior = maior;
            maior = numero;
        }
    }
    
    printf("Maior valor da sequência: %d.\n", maior);
    printf("Segundo maior valor: %d.\n", segundo_maior);

    return 0;
}

int main()
{
    int sequencia;
    printf("Digite a quantidade de números que deseja comparar: ");
    scanf("%d", &sequencia);

    maior_numero(sequencia);

    return 0;
}
