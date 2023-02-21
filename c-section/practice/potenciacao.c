#include <stdio.h>

int main()
{
    int x;
    int y; 
    int i = 1, potencia = 1;

    printf("Digite um número inteiro que queira elevar a uma potência: ");
    scanf("%d", &x);
    printf("Agora digite uma potência inteira para este número: ");
    scanf("%d", &y);

    while(i <= y)
    {
        potencia *= x;
        i++;
    }

    printf("%d elevado a %d é igual a %d\n.", x, y, potencia);

    return 0;
}
