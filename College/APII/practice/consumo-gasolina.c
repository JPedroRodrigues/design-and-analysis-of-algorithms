/*
Técnica de refinamentos sucessivos top-down (código se encontra abaixo)

Topo: Programa que calcula a quantidade de km rodados por litro

1° refinamento
Inicializar as variáveis
Receber a quantidade de litros abastecidos e de km rodados
Calcular a quantidade de km percorridos por Litro de gasolina abastecido

2° refinamento
declarar a variavel litros_gasolina e gasolina_total em 0
declarar a variavel km_rodados e km_total em 0
declarar a variavel eficiencia


loop infinito
    receber o numero de litros e atribuir a litros_gasolina
    se o número digitado for -1
        término a repetição
    incrementar a quantidade de litros a gasolina_total

    receber o numero de km rodados e atribuir a km_rodados
    incrementar o numero de km rodados e atribuir a km_total

    calcular a divisão de km_rodados por litros_gasolina e atribuir à eficiencia
    mostrar a eficiencia na tela

atribuir a eficiencia o valor da divisão de km_total por gasolina_total
mostrar eficiencia total
*/

#include <stdio.h>

int main()
{
    float litros_gasolina, gasolina_total = 0; 
    float km_rodados, km_total = 0;
    float eficiencia = 0;

    while (1)
    {
        printf("Digite a quantidade de litros abastecidos (-1 para encerrar): ");
        scanf("%f", &litros_gasolina);
        if (litros_gasolina == -1)
        {
            printf("Programa encerrado com sucesso.\n\n");
            break;
        }
        gasolina_total += litros_gasolina;

        printf("Insira a quantidade de Km rodados desde o abastecimento anterior: ");
        scanf("%f", &km_rodados);
        km_total += km_rodados;
        
        eficiencia = km_rodados / litros_gasolina;
        printf("O consumo atual é de %.3f Km/L.\n\n", eficiencia);
    }

    eficiencia = km_total / gasolina_total;
    printf("Consumo geral foi de %.3f Km/L.\n", eficiencia);

    return 0;
}
