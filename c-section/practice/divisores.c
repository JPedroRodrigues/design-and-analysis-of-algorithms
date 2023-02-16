#include <stdio.h>

int main()
{
    int numero, i;

    printf("Digite um número inteiro e mostrarei seus divisores: ");
    scanf("%d", &numero);

    printf("Os divisores de %d são:", numero);
    for (i = 1; i <= numero; i++)
    {
        if (numero % i == 0)
        {
            printf(" %d", i);
        }
    }

    return 0;
}