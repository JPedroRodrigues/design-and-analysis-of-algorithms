#include <stdio.h>

int main(){
    int numero, i, soma_divisores = 0;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    for (i = 1; i <= numero; i++)
    {
        if (numero % i == 0)
        {
            soma_divisores += i;
        }
    }

    if (soma_divisores == numero * 2)
    {
        printf("%d é um número inteiro perfeito.\n", numero);
    }
    else
    {
        printf("%d NÃO é um número inteiro perfeito.\n", numero);
    }

    return 0;
}