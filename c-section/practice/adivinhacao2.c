#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));

    int numero_aleatorio = 1 + (rand() % 100);
    int palpite;
    int contador = 1;

    // Validação da entrada
    do
    {
        printf("Tente adivinhar um número entre 1 e 100: ");
        scanf("%d", &palpite);
    }
    while (palpite < 1 || palpite > 100);

    //Verificação do palpite
    while (palpite != numero_aleatorio)
    {
        if (palpite > numero_aleatorio)
        {
            contador++;
            printf("Você chutou muito alto! Tente novamente: ");
            scanf("%d", &palpite);
        }
        else if (palpite < numero_aleatorio)
        {
            contador++;
            printf("Você chutou muito baixo! Tente acertar novamente: ");
            scanf("%d", &palpite);
        }
    }

    // Resultado
    printf("Parabéns!! Você acertou!\n");
    printf("Você precisou de %d tentativas para conseguir acertar o número corretamente. Muito bem!\n", contador);

    return 0;
}