#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int numero_aleatorio = 1 + rand() % 100;
    int palpite;
    int contador = 1;

    // Validação do palpite
    do
    {
        printf("Tente adivinhar um número entre 1 e 100: "); 
        scanf("%d", &palpite);
    }
    while(palpite < 1 || palpite > 100);

    // Verificação dos resultados
    while (palpite != numero_aleatorio && contador < 5)
    {
        if (palpite > numero_aleatorio)
        {
            contador++;
            printf("Muito alto! Tente novamente: ");
            scanf("%d", &palpite);
        }
        else if (palpite < numero_aleatorio)
        {
            contador++;
            printf("Muito baixo! Tente novamente: ");
            scanf("%d", &palpite);
        }
    }

    // Resultado final
    if (contador == 5)
    {
        printf("Você excedeu o número máximo de tentativas. Número sorteado: %d.\n", numero_aleatorio);
    } 
    else
    {
        printf("Você acertou! Parabéns!\n");
        printf("Número de tentativas: %d.\n", contador);
    }

    return 0;
}