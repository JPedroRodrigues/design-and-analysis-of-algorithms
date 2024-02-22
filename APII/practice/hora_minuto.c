#include <stdio.h>

void minuto(int hora1, int minuto1, int hora2, int minuto2)
{   
    int diferenca_min, diferenca_hora;
    if (hora1 >= hora2)
    {
        diferenca_min = minuto1 - minuto2;
        diferenca_hora = hora1 - hora2;
    }
    else
    {
        diferenca_min = minuto2 - minuto1;
        diferenca_hora = hora2 - hora1;
    }
    
    if (diferenca_min < 0)
    {
        diferenca_hora -= 1;
        diferenca_min += 60;
    }

    printf("Diferença: %d:%dh.\n", diferenca_hora, diferenca_min);
}


int main()
{
    int hora1, hora2, minuto1, minuto2;

    do 
    {
        printf("Digite um horário no formato \"h:m\": ");
        scanf("%d:%d", &hora1, &minuto1);
    } while (hora1 < 0 && minuto1 < 0);

    do
    {
       printf("Digite outro horário seguindo o mesmo formato: ");
       scanf("%d:%d", &hora2, &minuto2);
    } while (hora2 < 0 && minuto2 < 0);
    
    minuto(hora1, minuto1, hora2, minuto2);

    return 0;
}