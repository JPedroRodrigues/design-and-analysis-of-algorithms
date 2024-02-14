#include <stdio.h>

int main()
{
    printf("Digite um número de 1 a 5: ");
    int n;
    scanf("%d", &n);

    switch(n)
    {
        case(1):
            printf("Um!\n");
            break;
        case(2):
            printf("Dois!\n");
            break;
        case(3):
            printf("Três\n");
            break;
        case(4):
            printf("Quatro!\n");
            break;
        case(5):
            printf("Cinco!\n");
            break;
        default:
            printf("O número precisa ser entre 1 e 5 (inclusivo)\n");
    }
    printf("Fim!\n");

    return 0;
}
